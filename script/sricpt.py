import os
import subprocess

fichier = os.listdir('/bin')
for i in fichier:
    x = '/bin/' + i
    subprocess.Popen(['./nm', x])