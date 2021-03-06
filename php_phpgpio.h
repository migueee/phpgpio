/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_PHPGPIO_H
#define PHP_PHPGPIO_H

extern zend_module_entry phpgpio_module_entry;
#define phpext_phpgpio_ptr &phpgpio_module_entry

#define PHP_PHPGPIO_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_PHPGPIO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_PHPGPIO_API __attribute__ ((visibility("default")))
#else
#	define PHP_PHPGPIO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(phpgpio);
PHP_MSHUTDOWN_FUNCTION(phpgpio);
PHP_RINIT_FUNCTION(phpgpio);
PHP_RSHUTDOWN_FUNCTION(phpgpio);
PHP_MINFO_FUNCTION(phpgpio);

PHP_FUNCTION(confirm_phpgpio_compiled);	/* For testing, remove later. */
PHP_FUNCTION(wiringPiSetup);	/* For testing, remove later. */
PHP_FUNCTION(wiringPiSetupGpio);	/* For testing, remove later. */
PHP_FUNCTION(wiringPiSetupPhys);	/* For testing, remove later. */
PHP_FUNCTION(wiringPiSetupSys);	/* For testing, remove later. */
PHP_FUNCTION(pinMode);	/* For testing, remove later. */
PHP_FUNCTION(pullUpDnControl);	/* For testing, remove later. */
PHP_FUNCTION(digitalWrite);	/* For testing, remove later. */
PHP_FUNCTION(pwmWrite);	/* For testing, remove later. */
PHP_FUNCTION(digitalRead);	/* For testing, remove later. */
PHP_FUNCTION(analogRead);	/* For testing, remove later. */
PHP_FUNCTION(analogWrite);	/* For testing, remove later. */

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(phpgpio)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(phpgpio)
*/

/* In every utility function you add that needs to use variables 
   in php_phpgpio_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PHPGPIO_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PHPGPIO_G(v) TSRMG(phpgpio_globals_id, zend_phpgpio_globals *, v)
#else
#define PHPGPIO_G(v) (phpgpio_globals.v)
#endif

#endif	/* PHP_PHPGPIO_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
