#ifndef CHTML_H
#define CHTML_H

#ifndef CHTML_FPRINTF
    #include <stdio.h>
    #define CHTML_FPRINTF fprintf
#endif

#ifndef CHTML_FCLOSE
    #include <stdio.h>
    #define CHTML_FCLOSE fclose
#endif

#ifndef CHTML_OPEN_MEMSTREAM
    #include <stdio.h>
    #define CHTML_OPEN_MEMSTREAM open_memstream
#endif

#ifndef CHTML_ASSERT
    #include <assert.h>
    #define CHTML_ASSERT assert
#endif

#define CHTML_SCOPE(atStart, atEnd) for (int _scope_break = ((atStart), 1); _scope_break; _scope_break = ((atEnd), 0))

#define HTML(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<html %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</html>"))

#define HEAD(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<head %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</head>"))
#define TITLE(format, ...) CHTML_FPRINTF(HTML_STREAM, "<title>" format "</title>", ##__VA_ARGS__)
#define META(attributes, ...) CHTML_FPRINTF(HTML_STREAM, "<meta " attributes ">", ##__VA_ARGS__)

#define BODY(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<body %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</body>"))
#define DIV(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<div %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</div>"))

#define H1(format, ...) CHTML_FPRINTF(HTML_STREAM, "<h1>" format "</h1>", ##__VA_ARGS__)
#define H2(format, ...) CHTML_FPRINTF(HTML_STREAM, "<h2>" format "</h2>", ##__VA_ARGS__)
#define H3(format, ...) CHTML_FPRINTF(HTML_STREAM, "<h3>" format "</h3>", ##__VA_ARGS__)
#define H4(format, ...) CHTML_FPRINTF(HTML_STREAM, "<h4>" format "</h4>", ##__VA_ARGS__)
#define H5(format, ...) CHTML_FPRINTF(HTML_STREAM, "<h5>" format "</h5>", ##__VA_ARGS__)
#define H6(format, ...) CHTML_FPRINTF(HTML_STREAM, "<h6>" format "</h6>", ##__VA_ARGS__)

#define TABLE(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<table %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</table>"))
#define TR(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<tr %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</tr>"))
#define TD(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<td %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</td>"))

#define LABEL(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<label %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</label>"))

#define FORM(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<form %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</form>"))
#define INPUT(format, ...) CHTML_FPRINTF(HTML_STREAM, "<input " format ">", ##__VA_ARGS__)
#define SELECT(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<select %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</select>"))
#define OPTION(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<option %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</option>"))
#define TEXTAREA(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<textarea %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</textarea>"))

#define BR() CHTML_FPRINTF(HTML_STREAM, "<BR>")
#define HR(format, ...) CHTML_FPRINTF(HTML_STREAM, "<hr " format ">", ##__VA_ARGS__)

#define P(format, ...) CHTML_FPRINTF(HTML_STREAM, "<p>" format "</p>", ##__VA_ARGS__)
#define B(format, ...) CHTML_FPRINTF(HTML_STREAM, "<b>" format "</b>", ##__VA_ARGS__)
#define EM(format, ...) CHTML_FPRINTF(HTML_STREAM, "<em>" format "</em>", ##__VA_ARGS__)
#define I(format, ...) CHTML_FPRINTF(HTML_STREAM, "<i>" format "</i>", ##__VA_ARGS__)
#define STRONG(format, ...) CHTML_FPRINTF(HTML_STREAM, "<strong>" format "</strong>", ##__VA_ARGS__)

#define A(format, ...) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<a " format ">", ##__VA_ARGS__), CHTML_FPRINTF(HTML_STREAM, "</a>"))
#define SPAN(attributes) CHTML_SCOPE(CHTML_FPRINTF(HTML_STREAM, "<span %s>", attributes), CHTML_FPRINTF(HTML_STREAM, "</span>"))
#define STRING(format, ...) CHTML_FPRINTF(HTML_STREAM, format, ##__VA_ARGS__)

#define HTML_BEGIN()                                                            \
    unsigned long long CHTML_BUFFER_SIZE;                                       \
    char *CHTML_BUFFER;                                                         \
                                                                                \
    FILE* HTML_STREAM = CHTML_OPEN_MEMSTREAM(&CHTML_BUFFER, &CHTML_BUFFER_SIZE);\
    CHTML_ASSERT(HTML_STREAM != NULL)                                           \

#define HTML_COMPILE() (CHTML_FCLOSE(HTML_STREAM), CHTML_BUFFER)

#endif