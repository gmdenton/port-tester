# Port Tester

[![GitHub license](https://img.shields.io/github/license/Naereen/StrapDown.js.svg)](https://github.com/Naereen/StrapDown.js/blob/master/LICENSE)


### Overview

Port tester is a set of two applications that can be used for testing socket connectivity.

The applications are designed for use in a secure / segregated network environment, where it is required to have firewall rules implemented to enable connectivity between network segments and application layers (IE Database, Middleware and web / client) or systems.

The applications are written in standard c++ and can be compiled on Windows, linux or Mac.

##### Port Client Application
The port client application is similar to Telnet or NC, which takes 2 parameters: host name / IP address and port number. The application will attempt to make a connection to the supplied host / IP address on the specified port. It will return a message if it succeeds or fails. 

The application can take either a single host / port as a command line parameter or a filename that contains a list of [host],[port] combinations. 

##### Port Server
The port server application is designed to be used on any Windows or Linux server to enable testing of socket connectivity, prior to installing any applications software.

The port server application reads a text file containing a list [host],[port] combinations. The Appplication will start a socket thread listening on each of the ports listed in the text file.

This enables connectivity testing without needing to wait for all the required application installations to be completed.
