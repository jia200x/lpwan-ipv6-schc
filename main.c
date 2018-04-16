#include <stdio.h>
#include "defs.h"

int main() {
    schc_rule_t *rule = schc_get_rule_by_id(1);
    printf("Pointer: %p\n", rule);
    printf("Is uplink rule: %i\n", schc_rule_is_uplink(rule));
    printf("Is downlink rule: %i\n", schc_rule_is_downlink(rule));
    printf("Next rule: %p\n", rule->rule[0].next);
    printf("Next rule: %p\n", schc_field_next(rule->rule));
    printf("Both rules: %p %p", &rule->rule[1], rule->rule[0].next);

    //Iterate through all rules:
    schc_field_desc_t *r = rule[0].rule;

    while(r) {
        printf("Current rule FID is: %i\n", r->fid);
        r = (schc_field_desc_t*) schc_field_next(r);
    }
    printf("End!\n");
    return 0;
}
