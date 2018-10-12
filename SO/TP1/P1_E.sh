#!/bin/bash
#		  print filenames_	found files	
#						  \		vv
find * -type f -exec grep -l $1 {} \; 
#								   ^^
#						escaped end of exec command