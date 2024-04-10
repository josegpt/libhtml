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

#ifndef __HTML_H__
#define __HTML_H__

enum html_element {
	BEGIN,
	TAG,
	SELFTAG,
	ATTRKEY,
	ATTRVAL,
	TEXT
};

struct html {
	enum html_element state;
};

void html_begin(struct html *);
void html_begintag(struct html *, const char *);
void html_beginselftag(struct html *, const char *);
void html_beginattr(struct html *, const char *);
void html_beginhead(struct html *);
void html_begintitle(struct html *);
void html_beginbody(struct html *);
void html_beginmeta(struct html *);
void html_beginclass(struct html *);
void html_begindata(struct html *, const char *);
void html_begincharset(struct html *);
void html_begincontent(struct html *);
void html_beginname(struct html *);
void html_beginproperty(struct html *);
void html_beginlink(struct html *);
void html_beginrel(struct html *);
void html_beginlang(struct html *);
void html_beginhref(struct html *);
void html_begintype(struct html *);
void html_beginas(struct html *);
void html_beginheader(struct html *);
void html_begindiv(struct html *);
void html_beginmain(struct html *);
void html_beginarticle(struct html *);
void html_beginul(struct html *);
void html_beginol(struct html *);
void html_beginli(struct html *);
void html_beginp(struct html *);
void html_beginnav(struct html *);
void html_begina(struct html *);
void html_begincode(struct html *);
void html_beginimg(struct html *);
void html_beginheight(struct html *);
void html_beginwidth(struct html *);
void html_beginsrc(struct html *);
void html_beginalt(struct html *);
void html_beginsection(struct html *);
void html_begintarget(struct html *);
void html_begincolor(struct html *);
void html_beginspan(struct html *);
void html_beginfooter(struct html *);
void html_beginsmall(struct html *);
void html_beginem(struct html *);
void html_beginh1(struct html *);
void html_beginh2(struct html *);
void html_beginh3(struct html *);
void html_beginh4(struct html *);
void html_beginh5(struct html *);
void html_beginh6(struct html *);

void html_end(struct html *);
void html_endtag(struct html *, const char *);
void html_endselftag(struct html *);
void html_endattr(struct html *);
void html_endhead(struct html *);
void html_endtitle(struct html *);
void html_endbody(struct html *);
void html_endmeta(struct html *);
void html_endclass(struct html *);
void html_enddata(struct html *);
void html_endcharset(struct html *);
void html_endcontent(struct html *);
void html_endname(struct html *);
void html_endproperty(struct html *);
void html_endlink(struct html *);
void html_endrel(struct html *);
void html_endlang(struct html *);
void html_endhref(struct html *);
void html_endtype(struct html *);
void html_endas(struct html *);
void html_endheader(struct html *);
void html_enddiv(struct html *);
void html_endmain(struct html *);
void html_endarticle(struct html *);
void html_endul(struct html *);
void html_endol(struct html *);
void html_endli(struct html *);
void html_endp(struct html *);
void html_endnav(struct html *);
void html_enda(struct html *);
void html_endcode(struct html *);
void html_endimg(struct html *);
void html_endheight(struct html *);
void html_endwidth(struct html *);
void html_endsrc(struct html *);
void html_endalt(struct html *);
void html_endsection(struct html *);
void html_endtarget(struct html *);
void html_endcolor(struct html *);
void html_endspan(struct html *);
void html_endfooter(struct html *);
void html_endsmall(struct html *);
void html_endem(struct html *);
void html_endh1(struct html *);
void html_endh2(struct html *);
void html_endh3(struct html *);
void html_endh4(struct html *);
void html_endh5(struct html *);
void html_endh6(struct html *);

void html_text(struct html *, const char *, ...);

#endif /* __HTML_H__ */
