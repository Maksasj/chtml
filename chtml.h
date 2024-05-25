#ifndef CHTML_H
#define CHTML_H

#include <stdio.h>

#define CHTML_SCOPE(atStart, atEnd) for (int _scope_break = ((atStart), 1); _scope_break; _scope_break = ((atEnd), 0))

#define HTML(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<html %s>", attributes), fprintf(HTML_STREAM, "</html>"))

#define HEAD(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<head %s>", attributes), fprintf(HTML_STREAM, "</head>"))
#define BODY(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<body %s>", attributes), fprintf(HTML_STREAM, "</body>"))
#define DIV(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<div %s>", attributes), fprintf(HTML_STREAM, "</div>"))

#define H1(format, ...) fprintf(HTML_STREAM, "<h1>" format "</h1>", ##__VA_ARGS__)
#define H2(format, ...) fprintf(HTML_STREAM, "<h2>" format "</h2>", ##__VA_ARGS__)
#define H3(format, ...) fprintf(HTML_STREAM, "<h3>" format "</h3>", ##__VA_ARGS__)
#define H4(format, ...) fprintf(HTML_STREAM, "<h4>" format "</h4>", ##__VA_ARGS__)
#define H5(format, ...) fprintf(HTML_STREAM, "<h5>" format "</h5>", ##__VA_ARGS__)
#define H6(format, ...) fprintf(HTML_STREAM, "<h6>" format "</h6>", ##__VA_ARGS__)

#define TABLE(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<table %s>", attributes), fprintf(HTML_STREAM, "</table>"))
#define TR(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<tr %s>", attributes), fprintf(HTML_STREAM, "</tr>"))
#define TD(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<td %s>", attributes), fprintf(HTML_STREAM, "</td>"))

#define LABEL(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<label %s>", attributes), fprintf(HTML_STREAM, "</label>"))

#define FORM(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<form %s>", attributes), fprintf(HTML_STREAM, "</form>"))
#define INPUT(format, ...) fprintf(HTML_STREAM, "<input " format ">", ##__VA_ARGS__)
#define SELECT(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<select %s>", attributes), fprintf(HTML_STREAM, "</select>"))
#define OPTION(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<option %s>", attributes), fprintf(HTML_STREAM, "</option>"))
#define TEXTAREA(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<textarea %s>", attributes), fprintf(HTML_STREAM, "</textarea>"))

#define BR() fprintf(HTML_STREAM, "<BR>")
#define HR(format, ...) fprintf(HTML_STREAM, "<hr " format ">", ##__VA_ARGS__)

#define P(format, ...) fprintf(HTML_STREAM, "<p>" format "</p>", ##__VA_ARGS__)
#define B(format, ...) fprintf(HTML_STREAM, "<b>" format "</b>", ##__VA_ARGS__)
#define EM(format, ...) fprintf(HTML_STREAM, "<em>" format "</em>", ##__VA_ARGS__)
#define I(format, ...) fprintf(HTML_STREAM, "<i>" format "</i>", ##__VA_ARGS__)
#define STRONG(format, ...) fprintf(HTML_STREAM, "<strong>" format "</strong>", ##__VA_ARGS__)

#define A(format, ...) CHTML_SCOPE(fprintf(HTML_STREAM, "<a " format ">", ##__VA_ARGS__), fprintf(HTML_STREAM, "</a>"))
#define SPAN(attributes) CHTML_SCOPE(fprintf(HTML_STREAM, "<span %s>", attributes), fprintf(HTML_STREAM, "</span>"))
#define STRING(format, ...) fprintf(HTML_STREAM, format, ##__VA_ARGS__)

#define TITLE(format, ...) fprintf(HTML_STREAM, "<title>" format "</title>", ##__VA_ARGS__)
#define META(attributes, ...) fprintf(HTML_STREAM, "<meta " attributes ">", ##__VA_ARGS__)

#define HTML_BEGIN()                                                            \
    size_t CHTML_BUFFER_SIZE;                                                   \
    char *CHTML_BUFFER;                                                         \
                                                                                \
    FILE* HTML_STREAM = open_memstream(&CHTML_BUFFER, &CHTML_BUFFER_SIZE);      \
    if (HTML_STREAM == NULL) {                                                  \
        perror("Error opening memory stream");                                  \
    }                                                                           \

#define HTML_COMPILE() (fclose(HTML_STREAM), CHTML_BUFFER)


#endif