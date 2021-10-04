/*
 * Auth: Marcus Benesch
 * Date: 09-19-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:   PREPROJECT-2, Header file for readline() and writeline() functions.
 */

/* ============================ prototypes ========================================= */
/*
 * Input Args:
 *   fd -- File descriptor that will be written to.
 *   str -- Pointer of the source buffer containing a string.
 * Returns:
 *   Function returns the number of characters successfully written (which could be 0),
 *   and -1 if an error has been encountered.
 */
extern int writeline( int fd, const char *str );
/* --------------------------------------------------------------------------------- */
/* Input Args:
 *   fd -- File descriptor that will be read until a newline, or EOF is encountered.
 *   destbuf -- Pointer to a character array where all read characters will be read.
 *              The buffer will be null-terminated regardless of the number of
 *              characters successfully read (even if 0).
 *   bufsz -- The size of the buffer that 'destbuf' points to.
 * Returns:
 *   Function returns the number of characters successfully read PLUS one.  So if
 *   an empty line is read, 1 is returned.  Function returns 0 if an EOF condition
 *   is detected.  Otherwise, it returns -1 if an error condition is encountered.
 */
extern int readline( int fd, char *buf, int bufsz );