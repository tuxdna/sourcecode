/* # Description */
/* # This is a filter that takes input in a form of diff, */
/* # strips certain garbage out of it, so git-apply can chew it */
/* # certain garbage: if you have lines like */
/* # */
/* #   diff --git a/arch/x86/hvm/svm/svm.c b/arch/x86/hvm/svm/svm.c */
/* #   index 31359a3..163a6cf 100644 */
/* #   diff --git a/arch/x86/nmi.c b/arch/x86/nmi.c */
/* #   index 53d15a5..b30df07 100644 */
/* #   --- a/arch/x86/nmi.c */
/* #   +++ b/arch/x86/nmi.c */
/* #   @@ -73,7 +73,7 @@ int nmi_active; */
/* #   #define P6_EVNTSEL_OS          (1 << 17) */
/* #   ... */
/* # */
/* # Then the first two lines (diff... and index ...) are garbage, */
/* # and they make git-apply kaboom. */


#include <stdio.h>
#include <string.h>

#define LINE_WIDTH_MAX 1024
#define LINES          3

// use the lines array as a circular queue to hold the buffer of lines
char lines[LINES][LINE_WIDTH_MAX] = {0};

int main(int argc, char *argv[]) {
  char buf[5] = {0};
  int c;
  int char_index = 0;
  int line_index = 0;
  int idx0, idx1, idx2;
  const char *line0;
  const char *line1;
  const char *line2;

  while(( c = getchar()) != EOF) {
    // append current character
    lines[line_index][char_index] = c;
    char_index ++;
    lines[line_index][char_index] = '\0';
    switch(c) {
    case '\n':
      // if we are in a new diff section, then
      //   if the previous section contains only 'index' line then discard it
      //   else print it
      // end
      idx0 = (LINES + line_index - 2) % LINES;
      idx1 = (LINES + line_index - 1) % LINES;
      idx2 = line_index;
      
      line0 = lines[idx0];
      line1 = lines[idx1];
      line2 = lines[idx2];

      if ( 
	 /* #   diff --git a/arch/x86/hvm/svm/svm.c b/arch/x86/hvm/svm/svm.c */
	 (strncmp(line0, "diff --git", 10) == 0) &&
	 /* #   index 31359a3..163a6cf 100644 */
	 (strncmp(line1, "index ", 6) == 0) &&
	 /* #   diff --git a/arch/x86/nmi.c b/arch/x86/nmi.c */
	 (strncmp(line2, "diff --git", 10) == 0)
	   ) {

	// do something here
	// what?

      }

      // switch to a new line
      line_index = (line_index + 1) % LINES;
      break;
    default:
      break;
    }
  }
}

