#include <stdlib.h>
#include <stdio.h>
#include "defs.h"


schc_field_desc_t rule_0[] = {
    FIELD_DESCRIPTION(FID_IPV6_VER, 4, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x06", rule_0, 0),
    FIELD_DESCRIPTION(FID_IPV6_DS, 8, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x00", rule_0, 1),
    FIELD_DESCRIPTION(FID_IPV6_FL, 20, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x00", rule_0, 2),
    FIELD_DESCRIPTION(FID_IPV6_LEN, 20, 1, DIR_IND_BI, MO_IGNORE, CDA_COMPUTE_LENGTH, "", rule_0, 3),
    FIELD_DESCRIPTION(FID_IPV6_NH, 8, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x11", rule_0, 4),
    FIELD_DESCRIPTION(FID_IPV6_HL, 8, 1, DIR_IND_BI, MO_IGNORE, CDA_NOT_SENT, "\xff", rule_0, 5),
    FIELD_DESCRIPTION(FID_IPV6_DEV_PREFIX, 64, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\xFE\x00\x00\x00\x00\x00\x00", rule_0, 6),
    FIELD_DESCRIPTION(FID_IPV6_DEV_IID, 64, 1, DIR_IND_BI, MO_IGNORE, CDA_DEV_IID, "", rule_0, 7),
    FIELD_DESCRIPTION(FID_IPV6_APP_PREFIX, 64, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\xFE\x00\x00\x00\x00\x00\x00", rule_0, 8),
    FIELD_DESCRIPTION(FID_IPV6_APP_IID, 64, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\x00\x00\x00\x00\x00\x00\x00\x01", rule_0, 9),
    FIELD_DESCRIPTION(FID_UDP_DP, 16, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\x7B", rule_0, 10),
    FIELD_DESCRIPTION(FID_UDP_AP, 16, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\x7C", rule_0, 11),
    FIELD_DESCRIPTION(FID_UDP_LEN, 16, 1, DIR_IND_BI, MO_IGNORE, CDA_COMPUTE_LENGTH, "", rule_0, 12),
    FIELD_DESCRIPTION(FID_UDP_CHKS, 16, 1, DIR_IND_BI, MO_IGNORE, CDA_COMPUTE_CHECKSUM, "", rule_0, 13),
    END_OF_TABLE
};

schc_rule_t rules[]={
    RULE(1, rule_0, DIR_IND_BI, rules, 0),
    END_OF_TABLE
};

schc_rule_t *schc_get_rule_by_id(int rule_id) {
    int i=0, r=0;
    while(r=rules[i].rule_id) {
        if (r == rule_id) {
            return &rules[i];
        }
        i++;
    }
    return NULL;
}

schc_rule_t const *schc_rule_next(schc_rule_t *rule) {
    return rule->next ? (rule->next->next ? rule->next : NULL) : NULL;
}

schc_field_desc_t const *schc_field_next(schc_field_desc_t *fd) {
    return fd->next ? (fd->next->next ? fd->next : NULL) : NULL;
}

int schc_rule_is_uplink(schc_rule_t *rule) {
    return rule->dir ==  DIR_IND_BI || rule->dir == DIR_IND_UP;
}

int schc_rule_is_downlink(schc_rule_t *rule) {
    return rule->dir ==  DIR_IND_BI || rule->dir == DIR_IND_DOWN;
}
