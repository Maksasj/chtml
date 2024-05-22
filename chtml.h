#ifndef CHTML_H
#define CHTML_H

#include <stdio.h>

#define SCOPE(atStart, atEnd) for (int _scope_break = ((atStart), 1); _scope_break; _scope_break = ((atEnd), 0))

#define HTML(attributes) SCOPE(fprintf(HTML_STREAM, "<html %s>", attributes), fprintf(HTML_STREAM, "</html>"))

#define HEAD(attributes) SCOPE(fprintf(HTML_STREAM, "<head %s>", attributes), fprintf(HTML_STREAM, "</head>"))
#define BODY(attributes) SCOPE(fprintf(HTML_STREAM, "<body %s>", attributes), fprintf(HTML_STREAM, "</body>"))

#define H1(format, ...) fprintf(HTML_STREAM, "<h1>" format "</h1>", ##__VA_ARGS__)
#define P(format, ...) fprintf(HTML_STREAM, "<p>" format "</p>", ##__VA_ARGS__)
#define TITLE(format, ...) fprintf(HTML_STREAM, "<title>" format "</title>", ##__VA_ARGS__)
#define META(attributes, ...) fprintf(HTML_STREAM, "<meta " attributes ">", ##__VA_ARGS__)

#define HTML_BEGIN()\
    size_t size;    \
    char *buffer;   \
                    \
    FILE* HTML_STREAM = open_memstream(&buffer, &size); \
    if (HTML_STREAM == NULL) {  \
        perror("Error opening memory stream");  \
    }   \

#define HTML_COMPILE() (fclose(HTML_STREAM), buffer)


#endif