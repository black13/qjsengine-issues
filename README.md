# QJSEngine Issues

This demonstrates some issues encountered while investigating the use of
`QJSEngine` for the main context of [PhantomJS](http://phantomjs.org/).

## Environment

It has been tested on MacOS X (10.8.3) using Qt5 (5.0.2).

# Example Run

```
$ ./bin/qjsengine-issues
Trying to use dot notation on QObject...
[FAILURE] Error: Cannot assign to non-existent property "hey"
    at :/app.js:4:10
Falling back to using Object.defineProperty on QObject...
[SUCCESS]

Calling new property...
hey
[SUCCESS]

[DONE]

Trying callback with signal
Throwing and catching exception
[SUCCESS]
Throwing and *not* catching exception
Segmentation fault: 11
```
