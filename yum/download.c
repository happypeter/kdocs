
I want to know how yum download pkgs, I think it is done here:

yum->yummain.py->cli.py
problems = self.downloadPkgs(downloadpkgs)

but maybe I do not need to modify this part to open auth_mysql protected area,
Now that ak and tk are available, why can't I just use these id&pw to open auth_mysql first, and then let yum
do download as how it is.
