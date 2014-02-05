Example 1 - Getting Started
===========================

This is the minimal example to demonstrate how to use edbee.

**WARNING** at the moment this example is completely useless. Edbee requires an external keymap for it's keybinding. The editor loads, but you cannot work with it. 
When issue #114 is solved (which is very soon), this example will work and demonstrates the minimum effort required to use edbee.

example1.cpp
===========================

This examples in icludes the edbee widget header:

```C++
#include "edbee/texteditorwidget.h"
```

And later uses it as main widget. 

```C++
edbee::TextEditorWidget editor;
win.setCentralWidget( &editor );
```



example1.pro
===========================

This is the project file for this example. The contents is straightforward. 
The most interesting line is the last line which includes the edbee sources. 


```
include(../edbee-lib/edbee-lib/edbee-lib.pri)
```


