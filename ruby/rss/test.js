function do_something() {
    var data = {"items":[{"link":"http://tuxdna.wordpress.com/2012/01/29/jruby-on-rails-with-rvm-fedora/","title":"JRuby on Rails with RVM ( on Fedora )","description":"First install RVM and set it up: To include RVM into your bash shell, add following line to ~/.bashrc: Now install JRuby and use it as default Ruby interpreter: Setup Rails environment: Lets create a new Rails application: Now go to http://localhost:3000/people/ Yay! Your new Rails application is up and running, powered by JRuby ( [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=411&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Sun, 29 Jan 2012 04:10:12 -0800"},{"link":"http://tuxdna.wordpress.com/2012/01/27/packaging-java-jars-as-rpm-packages/","title":"Packaging Java JARs as RPM packages","description":"At JUDCon 2012, I had a discussion and argument with Jaikiran Pai and Ravi Maurya on &#8220;Packaging Java JARs as RPM packages&#8221;. Well it is not just RPM, it could be any package management system ( eg. dpkg, protage etc. ), doesn&#8217;t matter as long as it serves the purpose of: automatic dependency resolution installation [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=407&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Fri, 27 Jan 2012 03:00:05 -0800"},{"link":"http://tuxdna.wordpress.com/2012/01/27/judcon-2012-an-experience/","title":"JUDCon 2012 – an experience!","description":"My first Java exclusive conference! I arrived at the venue right on time. Surprize, there were a lot of people already holding their welcome kits. Conference was already running quite smoothly. Wifi worked most of the time. The sessions, lunch, tea were always on time. Actually, there were people assigned to ring bells, just like [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=389&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Thu, 26 Jan 2012 23:21:21 -0800"},{"link":"http://tuxdna.wordpress.com/2012/01/14/potential-bug-in-ruby-bindings-of-apache-qpid/","title":"Potential bug in Ruby bindings of Apache Qpid","description":"I wanted to experiment with Ruby bindings of Apache Qpid. Lets install the the server and client: Now check which version of Ruby bindings have we installed here: Okay, now lets create a simple script and send some messages. On running the script we should get a &#8220;Hello world!&#8221; message. This is not what we [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=383&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Sat, 14 Jan 2012 03:14:10 -0800"},{"link":"http://tuxdna.wordpress.com/2011/12/10/symlink-loop-is-still-an-unsolved-problem/","title":"Symlink loop is still an unsolved problem","description":"How do I dereference a symbolic link? $ ls -l /usr/bin/java lrwxrwxrwx. 1 root root 22 Jul 20 2010 /usr/bin/java -&#62; /etc/alternatives/java $ ls -l /etc/alternatives/java lrwxrwxrwx. 1 root root 30 Aug 9 2010 /etc/alternatives/java -&#62; /usr/java/jdk1.6.0_20/bin/java $ ls -l /usr/java/jdk1.6.0_20/bin/java -rwxr-xr-x. 1 root root 50810 Apr 13 2010 /usr/java/jdk1.6.0_20/bin/java Lets create a chain of [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=378&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Sat, 10 Dec 2011 01:05:01 -0800"},{"link":"http://tuxdna.wordpress.com/2011/11/29/how-to-resize-a-vm-and-its-partitions/","title":"How to resize a VM and its partitions?","description":"In this post I am going to list the steps to resize a Virtual Machine image created using virt-install There are three steps: Resize the VM image Resize the LVM volume inside the VM ( both physical volume and logical volume ) Resize the filesystem on the LVM volume First locate where the image for [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=368&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Tue, 29 Nov 2011 01:20:52 -0800"},{"link":"http://tuxdna.wordpress.com/2011/11/28/zif-critical-errors/","title":"zif critical errors","description":"Every once in a while I get these errors when installing a package using zif: Although the packages get installed, this is makes me uncomfortable. And how are these stack-traces generated for C code ?<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=364&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Mon, 28 Nov 2011 07:46:48 -0800"},{"link":"http://tuxdna.wordpress.com/2011/11/24/zif-package-management-done-faster/","title":"zif – Package management done faster","description":"On Fedora 16, I used zif. zif is an alternative to yum and its fast! How to setup zif? So easy: sudo yum install zif zif-tools All set! Search for packages using zif: sudo zif search mongodb Do a offline serach ( like cached -C in yum ): sudo zif search -o mongodb Install packages [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=357&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Thu, 24 Nov 2011 04:42:58 -0800"},{"link":"http://tuxdna.wordpress.com/2011/11/17/how-to-setup-multiple-monitors-on-xfce-desktop/","title":"How to setup multiple monitors on Xfce desktop?","description":"How to setup multiple monitors on Xfce desktop? I just followed the instructionson Xorg RandR 1.2 wiki http://www.thinkwiki.org/wiki/Xorg_RandR_1.2 Lets find out how many monitors we have connected? Now ask Xrandr to configure them: Now thats simply cool!<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=350&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Wed, 16 Nov 2011 21:49:22 -0800"},{"link":"http://tuxdna.wordpress.com/2011/11/15/emacs-key-binding-ctrlspace-not-working-on-fedora-16-gnome-or-xfce/","title":"Emacs key binding Ctrl+Space not working on Fedora 16 GNOME or XFCE","description":"I installed Fedora 16 x86_64 and then installed Emacs. Then I logged in into (XFCE or GNOME) desktop and started Emacs. For text selection in Emacs I use Ctrl+Space ( which is the default in Emacs ), and is no longer working. So I cannot select text using Ctr+Space. However, if I login into virtual [...]<img alt=\"\" border=\"0\" src=\"http://stats.wordpress.com/b.gif?host=tuxdna.wordpress.com&amp;blog=10303502&amp;post=346&amp;subd=tuxdna&amp;ref=&amp;feed=1\" width=\"1\" height=\"1\" />","pub_date":"Mon, 14 Nov 2011 21:40:30 -0800"}],"link":"http://tuxdna.wordpress.com","title":"DNA of the TUX","description":"Organized thoughts"};
    var blog_div = $("#blog_content");
    //blog_div.html();
    var blog_item = $('<p><a href=');
    var i = 0;
    for(i = 0; i < data.items.length; i++) {
	var item = data.items[i];
	var title = item.title;
	var link = item.link;
	var descriptoin = item.description;
	var pub_date = item.pub_date;
    }
}
