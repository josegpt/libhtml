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
	html_begintag(&html, "body");
	html_text(&html, "Hello %s!", "Jose");
	html_endtag(&html, "body");
	html_end(&html);

	putchar('\n');

	/* Self Close */
	html_begin(&html);
	html_beginselftag(&html, "meta");
	html_beginattr(&html, "content");
	html_text(&html, "josegpt");
	html_endattr(&html);
	html_beginattr(&html, "name");
	html_text(&html, "author");
	html_endattr(&html);
	html_endselftag(&html);
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_begintag(&html, "body");
	html_beginattr(&html, "class");
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endattr(&html);
	html_endtag(&html, "body");
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_begintag(&html, "body");
	html_beginattr(&html, "class");
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endattr(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_endtag(&html, "body");
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_beginattr(&html, "class");
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_endattr(&html);
	html_begintag(&html, "body");
	html_beginattr(&html, "class");
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endattr(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_endtag(&html, "body");
	html_end(&html);

	putchar('\n');

	html_begin(&html);
	html_beginattr(&html, "class");
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_endattr(&html);
	html_begintag(&html, "body");
	html_beginattr(&html, "class");
	html_text(&html, "cover");
	html_text(&html, "stack");
	html_text(&html, "cluster");
	html_endattr(&html);
	html_beginattr(&html, "data-justify");
	html_text(&html, "space-between");
	html_endattr(&html);
	html_text(&html, "Hello %s!", "Jose");
	html_endtag(&html, "body");
	html_end(&html);

	return EXIT_SUCCESS;
}