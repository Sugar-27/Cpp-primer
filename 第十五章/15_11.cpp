#include "15_11.h"

int main() {
    Quote q("textbook", 5);
	Bulk_quote b("notebook", 2.5, 10, 0.3);
    Limit_quote x("storybook", 4, 5, 0.5);
    q.debug();
    b.debug();
    x.debug();

    return 0;
}