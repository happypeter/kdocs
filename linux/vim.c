VIM command
>>>undo-redo
u
Ctrl+R
>>>delete the following 100 lines
d100

>>>jump 10 line
10+Enter
>>>go to specific line
:23
//go to line 23

>>>substtution
%s/god/dog/gc

>>>
b 	To the beginning of a word.
B 	To the beginning of a whitespace-delimited word.
0 	To the beginning of a line.
^ 	To the first non-whitespace character of a line.
$ 	To the end of a line.
H 	To the first line of the screen.

M 	To the middle line of the screen.
L 	To the the last line of the screen.
:n 	Jump to line number n. For example, to jump to line 42, you'd type :42

Deleting text
Vim command 	Action
x 	Delete characters under the cursor.
X 	Delete characters before the cursor.
dd or :d 	Delete the current line.

Search
Vim command 	Action
/pattern 	Search the file for pattern.
n 	Scan for next search match in the same direction.
N 	Scan for next search match but opposite direction.

gg	jump to the top
>>>r+otherkey-----------replace one character

>>> press End, to jump to the end of a line.
 press Home, to jump to the beginning of a line.


