# CHTML

Little single header library for generating HTML code. 
> Original idea from this Reddit post [there](https://www.reddit.com/r/C_Programming/comments/11at6d8/generate_html_in_c/)

## Example
This is a little usage example, that generates very simple html code

```c
#include "chtml.h"

int main() {
    HTML_BEGIN()

    HTML("lang='en'") {
        HEAD("") {
            META("charset='UTF-8'");
            // ...
        }
        BODY("") {
            H1("Hello world !");
            P("This is and CHTML example");
            
            for(int i = 0; i < 5; ++i)
                P("You also can use C code there %d like this", i);
        }
    } 

    char* string = HTML_COMPILE();
    printf("%s", string); // Result is just a html code
    free(string);

    return 0;
}
```

## License
**CHTML** is free and open source library/software. All code in this repository is licensed under
- MIT License ([LICENSE.md](https://github.com/Maksasj/chtml/blob/master/LICENSE.md) or https://opensource.org/license/mit/)