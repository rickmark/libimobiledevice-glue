/*
 * jsmn.h
 * Simple JSON parser (header file)
 *
 * Copyright (c) 2010 Serge A. Zaitsev
 *
 * Adapted for use in libimobiledevice-glue by Rick Mark
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __LIMD_GLUE_JSON_H_
#define __LIMD_GLUE_JSON_H_

/**
 * JSON type identifier. Basic types are:
 * 	o Object
 * 	o Array
 * 	o String
 * 	o Other primitive: number, boolean (true/false) or null
 */
typedef enum {
	JSON_PRIMITIVE = 0,
	JSON_OBJECT = 1,
	JSON_ARRAY = 2,
	JSON_STRING = 3
} LIMD_json_type_t;

typedef enum {
	/* Not enough tokens were provided */
	JSON_ERROR_NOMEM = -1,
	/* Invalid character inside JSON string */
	JSON_ERROR_INVAL = -2,
	/* The string is not a full JSON packet, more bytes expected */
	JSON_ERROR_PART = -3,
	/* Everything was fine */
	JSON_SUCCESS = 0
} LIMD_json_err_t;

/**
 * JSON token description.
 * @param		type	type (object, array, string etc.)
 * @param		start	start position in JSON data string
 * @param		end		end position in JSON data string
 */
typedef struct {
	LIMD_json_type_t type;
	int start;
	int end;
	int size;
#ifdef JSON_PARENT_LINKS
	int parent;
#endif
} LIMD_json_tok_t;

/**
 * JSON parser. Contains an array of token blocks available. Also stores
 * the string being parsed now and current position in that string
 */
typedef struct {
	size_t pos; /* offset in the JSON string */
	size_t toknext; /* next token to allocate */
	int toksuper; /* superior token node, e.g parent object or array */
} LIMD_json_parser;

/**
 * Create JSON parser over an array of tokens
 */
void LIMD_json_init(LIMD_json_parser *parser);

/**
 * Run JSON parser. It parses a JSON data string into and array of tokens, each describing
 * a single JSON object.
 */
LIMD_json_err_t LIMD_json_parse(LIMD_json_parser *parser, const char *js,
		LIMD_json_tok_t *tokens, unsigned int num_tokens);

#endif /* __JSMN_H_ */
