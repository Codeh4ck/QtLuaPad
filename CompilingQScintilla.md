<h3>A tutorial which teaches you how to compile QScintilla, which is essential for QtLuaPad to be compiled.</h3>

# Introduction #

1) First of all you'll need the QScintilla library which can be found here: <a href='http://www.riverbankcomputing.co.uk/software/qscintilla/download'>QScintilla</a>.

2) Create a folder on desktop called <b>"QScintilla"</b> and extract the library into it. Then run Qt commandline.

3) Now, you'll have to change your directory to the <b>"Qt4"</b> folder which is located inside the <b>"QScintilla"</b> folder on desktop.<br />
<tt>You can change your directory by using the "cd" command.<br />For intance: <b><i>cd C:/Users/Delirium/Desktop/QScintilla/Qt4</i></b></tt>

4) Now that you changed your directory to the <b>"Qt4"</b> folder, run these commands: <br />
<b><i><tt>qmake qscintilla.pro</tt><br /></i></b>
<b><i><tt>mingw32-make</tt><br /></i></b>
<b><i><tt>mingw32-make install</tt></i></b>

5) If your build was successful run this command to finalise it: <br />
<tt><b><i>copy %QTDIR%\lib\qscintilla2.dll %QTDIR%\bin</i></b></tt>

6) Copy your qscintilla2.dll to your windows/system folder and you're done!