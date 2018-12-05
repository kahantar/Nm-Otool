import os
import subprocess

fichier = os.listdir('/usr/bin')
for i in fichier:
    x = '/usr/bin/' + i
    subprocess.Popen(['./nm', x])
	
