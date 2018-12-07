import os
import subprocess
import difflib

lst = os.listdir('/bin')
for i in lst:
	x = '/bin/' + i
	subprocess.Popen(['./nm', x]) > fichier
	subprocess.Popen(['nm', x]) > fichier2
	#d = difflib.Differ()
	#diff = d.compare(fichier, fichier2)
	#print '\n'.join(diff)
	
