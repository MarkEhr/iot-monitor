#include <Arduino.h>


String HTTP_HEADER_200 = "HTTP/1.1 200 OK\n";

String HTTP_HEADER_CONTENT_HTML = "Content-type:text/html\n";
String HTTP_HEADER_CONTENT_JSON = "Content-type:application/json\n";

String HTTP_HEADER_CONNECTION_CLOSE = "Connection: close\n";


// if the current line is blank, you got two newline characters in a row.
// that's the end of the client HTTP request, so send a response:
String WEB_PAGE = 
    HTTP_HEADER_200 +
    HTTP_HEADER_CONTENT_HTML + 
    HTTP_HEADER_CONNECTION_CLOSE + "\n" +
    "<html><head><title>La plantita</title></head><body><h1>Soy la planta de Mark</h1>";


