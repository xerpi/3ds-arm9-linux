/*
 * $Id: edit_field.h 317 2005-10-02 21:32:49Z pepsiman $
 *
 * Interface of edit_field.c
 */

#ifndef EDIT_FORM_H_incl
#define EDIT_FORM_H_incl 1

#include <form.h>

#define EDIT_FIELD(c) (MAX_FORM_COMMAND + c)

extern void help_edit_field(void);
extern int edit_field(FORM * form, int *result);

#endif /* EDIT_FORM_H_incl */
