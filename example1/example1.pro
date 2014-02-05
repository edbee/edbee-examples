
# these are all qt libraries required for edbee
QT = core gui widgets
TEMPLATE = app

# the sources of this project
SOURCES = example1.cpp

# include the edbee project include file 
include(../edbee-lib/edbee-lib/edbee-lib.pri)

