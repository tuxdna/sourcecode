#!/usr/bin/python
import rpm
import json
import sys

class SpecInfo():
    def __init__(self, specfile):
        self.specfile = specfile
        self.patches = self.sources = self.files = self.changelogs = []
        self.package_info = {}
        for k in ["NAME", "VERSION", "RELEASE", "GROUP", "SIZE",
                  "LICENSE", "VENDOR", "URL", "SUMMARY", "DESCRIPTION"]:
            self.package_info[k] = None

        # initialize now
        self.initialize()

    def initialize(self):
        ts = rpm.TransactionSet()
        spec = ts.parseSpec(specfile)
        srcHeader = spec.sourceHeader
        # extarct info
        for k in ["NAME", "VERSION", "RELEASE", "GROUP", "SIZE",
                  "LICENSE", "VENDOR", "URL", "SUMMARY", "DESCRIPTION"]:
            query_string = "%{"+k+"}"
            query_output = spec.sourceHeader.sprintf(query_string)
            self.package_info[k] = query_output

        # extarct patches and sources list
        self.patches = spec.sourceHeader.sprintf("[%{PATCH}\n]").split()
        self.sources = spec.sourceHeader.sprintf("[%{SOURCE}\n]").split()
        # extract changelog
        fld_sep = "2fc76c04c5ee6503a5d6837605ddf805" # echo "field_separator" | md5sum
        et_sep = "95acf155024b615bd670b53a04ff9e49" # echo "entry_separator" | md5sum
        querytag = '[%{CHANGELOGNAME}' + fld_sep + "%{CHANGELOGTIME}" + fld_sep + "%{CHANGELOGTEXT}" + et_sep + "]"
        self.changelogs = [ k.split(fld_sep) for k in spec.sourceHeader.sprintf(querytag).split(et_sep) ]

    def dump_as_json(self, outfile):
        f = open(outfile, 'w')
        ds = { 
            "info": self.package_info,
            "patches": self.patches,
            "sources": self.sources,
            "changelogs": self.changelogs
            }
        json_content = json.dumps(ds)
        f.write(json_content)
        f.close()


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print "Insuficient arguments"

    specfile = sys.argv[1]
    json_out_file = sys.argv[2]
    print specfile
    si = SpecInfo(specfile)
    si.dump_as_json(json_out_file)

    
    print "patches: "
    for p in si.patches:
        print "    "+p

    print "source files: "
    for s in si.sources:
        print "    "+s

    print "info: "
    for k in si.package_info.keys():
        print "%s:\n    %s"%(k, si.package_info[k])

    print "changelog: "
    for s in si.changelogs:
        print "    "+", ".join(s)
