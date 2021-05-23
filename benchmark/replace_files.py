import os
import sys
from shutil import copyfile

def replace_file(file, og_file, suffix):
    try:
        copyfile(og_file, f'{og_file}{suffix}')
        os.rename(file, og_file)
    except:
        pass

def replace_all_files(files, og_files, suffix):
    for file, og_file in zip(files, og_files):
        replace_file(file, og_file, suffix)
        
def get_files_with(tldir, match):
    files = []
    for dirname, _, filenames in os.walk(tldir):
        files.extend(list(map(lambda f: f'{dirname}/{f}', filenames)))
    return list(filter(lambda f: match in f, files))

def main():
    if len(sys.argv) != 5:
        print("usage replace_files.py <dir> <suffix-before> <suffix-after> <suffix-collision>")
        exit(1)
    tldir = sys.argv[1]
    before = sys.argv[2] #'.c.chisel.c'
    after = sys.argv[3] #'.c'
    collision_suffix = sys.argv[4] #'.og'
    files = get_files_with(tldir, before)
    og_files = list(map(lambda f: f.replace(before, after), files))
    replace_all_files(files, og_files, collision_suffix)

main()