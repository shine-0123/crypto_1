import os
import importlib
import sys
import shutil
from importlib.machinery import SourceFileLoader

# Creating path where are stored dll files and fix script
fix_path=os.environ['TEST_VPCONFIG']
fix_path=fix_path[:(fix_path.index('VDK')+3)]+'\\patches\\'


# importing list of dll files and destination paths
SourceFileLoader('file_list',fix_path+os.environ['TEST_VDK_TEMPLATE']+'\\'+os.environ['TEST_VDK_VERSION']+'\\file_list.py').load_module()
from file_list import files

# creating source and destination paths to copy
output = os.environ['DATA_OUTPUT_FOLDER']
src_dir= fix_path+os.environ['TEST_VDK_TEMPLATE']+'\\'+os.environ['TEST_VDK_VERSION']

# applying patches
def Apply_Fix():
    print ("\nCopying fix libraries\n")
    for x in range(int(len(files)/2)):
        try:
            src=src_dir+'\\'+files[x*2]
            dest=output+files[x*2+1]+"\\"+files[x*2]
        except:
            print ("Error: List of files is empty or not correct")
            break
        
        print ("Copying:",src,"to",dest)
        try:
            shutil.copyfile(src,dest)
        except:
            print ("Error: source or destination not exists or is wrong")
        else:
            print ("Success\n")
    print ("Finish")
    