import os
import sys

import rpm

def getRPMInformation(rpmPath):
    ts = rpm.ts();
    try:
        fdno = os.open(rpmPath, os.O_RDONLY)
        hdr = ts.hdrFromFdno(fdno)
        os.close(fdno)
    except:
        raise

    rpmInfo = {}
    for k in ['name', 'summary', 'description', 'release', 'arch',
              'version', 'epoch', 'buildtime', 'size', 'archivesize',
              'group']:
        rpmInfo[k] =  hdr[k]

    rpmInfo['SOURCES'] = hdr[rpm.RPMTAG_SOURCE]
    rpmInfo['PATCHES'] = hdr[rpm.RPMTAG_PATCH]
    return rpmInfo


if __name__ == '__main__':
    
    filename = sys.argv[1]
    print "Reading ", filename
    print ""
    rpmInfo = getRPMInformation(filename)

    if not rpmInfo:
        print "No rpm information"
        sys.exit(-1)

    for k in rpmInfo.keys():
        v =  rpmInfo[k]
        if k == 'PATCHES':
            values = v[:]
            values.reverse()
            for p in values:
                print p
        else:
            print k,":", v

