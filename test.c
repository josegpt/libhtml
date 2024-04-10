#include <stdio.h>
#include <stdlib.h>

#define HTML_IMPLEMENTATION
#include "html.h"

static struct html html;

int
main(void)
{
	html_begin(&html);
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_beginbody(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_endbody(&html);
	html_end(&html);

	putchar('\n');

	/* Self Close */
	html_begin(&html);
	html_beginmeta(&html);
	html_begincontent(&html);
	html_text(&html, "josegpt");
	html_endcontent(&html);
	html_beginname(&html);
	html_text(&html, "author");
	html_endname(&html);
	html_endmeta(&html);
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_beginbody(&html);
	html_beginclass(&html);
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endclass(&html);
	html_endbody(&html);
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_beginbody(&html);
	html_beginclass(&html);
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endclass(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_endbody(&html);
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_beginclass(&html);
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_endclass(&html);
	html_beginbody(&html);
	html_beginclass(&html);
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endclass(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_endbody(&html);
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_beginclass(&html);
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_endclass(&html);
	html_beginbody(&html);
	html_beginclass(&html);
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endclass(&html);
	html_begindata(&html, "justify");
	html_text(&html, "space-between");
	html_enddata(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_endbody(&html);
	html_end(&html);

	return EXIT_SUCCESS;
}

