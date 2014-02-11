#!/bin/sh

old_dir=`pwd`
cd `dirname $0`
script_dir=`pwd`
cd $old_dir

rm -f $script_dir/*~
rm -f $script_dir/*aux
rm -f $script_dir/*backup
rm -f $script_dir/*log
rm -f $script_dir/*bbl
rm -f $script_dir/*lof
rm -f $script_dir/*log
rm -f $script_dir/*lot
rm -f $script_dir/*nav
rm -f $script_dir/*toc
rm -f $script_dir/*out
rm -f $script_dir/*snm
rm -f $script_dir/*blg
rm -f $script_dir/*vrb

