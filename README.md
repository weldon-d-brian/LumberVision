LumberVision
============

Sample of using alglib to detect lumber geometry
http://www.alglib.net/
-------------------------------------------------

This Visual Studio 2013 C++ program uses the Strategy pattern (http://en.wikipedia.org/wiki/Strategy_pattern) and 
Dependency Injection (http://en.wikipedia.org/wiki/Dependency_injection) to setup a clean extensible image
processing framework. The base class is ImageProcessingStrategy, users should derive their new classes
from this. The user is required to override the execute() function and encapsulate their image processing algorithm
there.

Visual Studio 2013 can be obtained here: http://www.microsoft.com/en-us/download/details.aspx?id=40787
