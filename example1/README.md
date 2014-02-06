Example 1 - Getting Started
===========================

This is the minimal example to demonstrate how to use edbee.

example1.cpp
===========================

The main source first includes the edbee widget header:

```C++
#include "edbee/texteditorwidget.h"
```

And later uses it as main widget. 

```C++
edbee::TextEditorWidget editor;
win.setCentralWidget( &editor );
```

That's all :)



example1.pro
===========================

This is the project file for this example. The contents is straightforward. 
The most interesting line is the last line which includes the edbee sources. 


```
include(../edbee-lib/edbee-lib/edbee-lib.pri)
```


