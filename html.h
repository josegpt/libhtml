/*
 * Copyright (c) 2024 Jose G Perez Taveras <josegpt27@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef HTML_H
#define HTML_H

enum html_element {
	BEGIN,
	TAG,
	ATTRKEY,
	ATTRVAL,
	TEXT
};

struct html {
	enum html_element state;
};

void html_begin(struct html *);
void html_begintag(struct html *, const char *);
void html_beginattr(struct html *, const char *);

void html_text(struct html *, const char *, ...);

void html_end(struct html *);
void html_endtag(struct html *, const char *);
void html_endattr(struct html *);

#endif /* HTML_H */

#ifdef HTML_IMPLEMENTATION

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static void
html_write(struct html *html, const char *str)
{
	fwrite(str, 1, strlen(str), stdout);
}

static void
html_writec(struct html *html, int c)
{
	fputc(c, stdout);
}

static void
html_writef(struct html *html, const char *format, va_list ap)
{
	vfprintf(stdout, format, ap);
}

void
html_begin(struct html *html)
{
	html_write(html, "<!doctype html>");
	html_begintag(html, "html");
}

void
html_end(struct html *html)
{
	html_endtag(html, "html");
}

void
html_begintag(struct html *html, const char *str)
{
	if (html->state == TAG) {
		html_writec(html, '>');
	}

	html_writec(html, '<');
	html_write(html, str);
	html->state = TAG;
}


void
html_endtag(struct html *html, const char *str)
{
	if (html->state == TAG)
		html_writec(html, '>');

	html_writec(html, '<');
	html_writec(html, '/');
	html_write(html, str);
	html_writec(html, '>');
	html->state = BEGIN;
}

void
html_beginattr(struct html *html, const char *str)
{
	if (html->state == TAG) {
		html_writec(html, ' ');
	}

	html_write(html, str);
	html_writec(html, '=');
	html_writec(html, '"');
	html->state = ATTRKEY;
}

void
html_endattr(struct html *html)
{
	html_writec(html, '"');
	html->state = TAG;
}

void
html_text(struct html *html, const char *format, ...)
{
	va_list ap;

	switch (html->state) {
	case TAG:
		html_writec(html, '>');
		html->state = TEXT;
	break;
	case ATTRKEY:
		html->state = ATTRVAL;
	break;
	case ATTRVAL:
		html_writec(html, ' ');
	break;
	}

	va_start(ap, format);
	html_writef(html, format, ap);
	va_end(ap);
}

#endif /* HTML_IMPLEMENTATION */