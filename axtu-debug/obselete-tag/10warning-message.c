===
adding a waring message is nothing but adding
QMessageBox::warning(this, tr("Warning"),"ppppppppppp");
in classGui.cpp

===
others/warning-message.patch
shows how to pass value from engine to gui,
and if I want to really use ob info, I can just implement
GetHeaderInfo() inside classRpmEngine::AddInstallElement()
===
it is easy, but this means add another two arrays into classEngine,
and mem leak will be easier. so I can just keep the patch and use it later
when I find a better structure for the code.
