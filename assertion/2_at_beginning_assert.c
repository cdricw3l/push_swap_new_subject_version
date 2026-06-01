/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_at_beginning_assert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:37:11 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/01 13:38:42 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void max_at_beg_asser(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int biggest;
    char *l1[] = {"10 5 -2 4001 311", NULL};
    char *l2[] = {"1 -5 20 40 3", NULL};
    char *l3[] = {"1 -5 20 40 3", NULL};
    char *l4[] = {"1 5 -20 40 3 0 78 44 58", NULL};
    char *l5[] = {"1 5 -20 -40 3 220 31 7 88 22", NULL};

    assert(init_global_data(l1, &data) == OK);
    while (data.a)
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
    assert(data.size_a == 0);
    display_stack(&data, STACK_B);
    assert(at_beginning(&data, STACK_B, bigest_value(&data, STACK_B)) == OK);
    assert(at_beginning(&data, STACK_B, bigest_value(&data, STACK_B)) == NO_MOVE);
    while (data.b)
    {
        biggest = *bigest_value(&data, STACK_B);
        at_beginning(&data, STACK_B, bigest_value(&data, STACK_B));
        assert(biggest == *data.b);
        push(&data,STACK_B, STACK_A, NO_DISPLAY);
    }
    assert(ft_is_sort(&data, STACK_A));
    
    assert(init_global_data(l2, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value(&data, STACK_A));
    assert(biggest == *(data.a));
    
    assert(init_global_data(l3, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value(&data, STACK_A));
    assert(biggest == *data.a);

    assert(init_global_data(l4, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value(&data, STACK_A));
    assert(biggest == *data.a);
    
    assert(init_global_data(l5, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value(&data, STACK_A));
    assert(biggest == *data.a);


    char *l6[] = {"10 -1 32 45 7 -788", NULL};
    assert(init_global_data(l6, &data) == OK);
    while (data.a)
    {
        biggest = *bigest_value(&data, STACK_A);
        at_beginning(&data, STACK_A, bigest_value(&data, STACK_A));
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
        assert(biggest == *data.b);
    }
    while (data.b)
    {
        biggest = *bigest_value(&data, STACK_B);
        at_beginning(&data, STACK_B, bigest_value(&data, STACK_B));
        push(&data, STACK_B, STACK_A, NO_DISPLAY);
        assert(biggest == *data.a);
    }
    ASSERT_END(__func__);
}
void min_at_beg_asser(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int smallest;
    char *l1[] = {"1 -5 2 4 3", NULL};
    char *l2[] = {"1 -5 20 40 3", NULL};
    char *l3[] = {"1 -5 20 40 3", NULL};
    char *l4[] = {"1 5 -20 40 3 0 78 44 58", NULL};
    char *l5[] = {"1 5 -20 -40 3 220 31 7 88 22", NULL};

    assert(init_global_data(l1, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value(&data, STACK_A));
    assert(smallest == *data.a);
    
    assert(at_beginning(&data, STACK_A, smalest_value(&data, STACK_A)) == NO_MOVE);
    assert(smallest == *data.a);
    
    assert(init_global_data(l2, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value(&data, STACK_A));
    assert(smallest == *(data.a));
    
    assert(init_global_data(l3, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value(&data, STACK_A));
    assert(smallest == *data.a);
    assert(init_global_data(l5, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value(&data, STACK_A));
    assert(smallest == *data.a);

    assert(init_global_data(l4, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value(&data, STACK_A));
    assert(smallest == *data.a);
    
    assert(init_global_data(l5, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value(&data, STACK_A));
    assert(smallest == *data.a);


    char *l6[] = {"10 -1 32 45 -7555 -788", NULL};
    assert(init_global_data(l6, &data) == OK);
    while (data.a)
    {
        smallest = *smalest_value(&data, STACK_A);
        at_beginning(&data, STACK_A, smalest_value(&data, STACK_A));
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
        assert(smallest == *data.b);
    }
    at_beginning(&data, STACK_B, smalest_value(&data, STACK_B));
    while (data.b)
    {
        smallest = *smalest_value(&data, STACK_B);
        display_stack(&data, STACK_B);
        at_beginning(&data, STACK_B, smalest_value(&data, STACK_B));
        push(&data, STACK_B, STACK_A, NO_DISPLAY);
        display_stack(&data, STACK_B);
        //assert(smallest == *data.a);
    }
    ASSERT_END(__func__);
}
void immediat_superior_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    char *s[] = {"8 4 2 1 7 14 5 0 11 10 3 19 15 13 20 17 6 18 16 12 9", NULL};
    assert(init_global_data(s, &data) == OK);

    assert(*immediat_superior(&data, STACK_A, data.a + 3) == *(data.a + 2));      //1   -> 2
    assert(*immediat_superior(&data, STACK_A, data.a + 2) == *(data.a + 10));     //2   -> 3
    assert(*immediat_superior(&data, STACK_A, data.a + 10) == *(data.a + 1));     //3   -> 4
    assert(*immediat_superior(&data, STACK_A, data.a + 1) == *(data.a + 6));      //4   -> 5    
    assert(*immediat_superior(&data, STACK_A, data.a + 6) == *(data.a + 16));     //5   -> 6
    assert(*immediat_superior(&data, STACK_A, data.a + 16) == *(data.a + 4));     //6   -> 7
    assert(*immediat_superior(&data, STACK_A, data.a + 4) == *(data.a));          //7   -> 8
    assert(*immediat_superior(&data, STACK_A, data.a) == *(data.a + 20));         //8   -> 9
    assert(*immediat_superior(&data, STACK_A, data.a + 20) == *(data.a + 9));     //9   -> 10
    assert(*immediat_superior(&data, STACK_A, data.a + 9) == *(data.a + 8));      //10  -> 11
    assert(*immediat_superior(&data, STACK_A, data.a + 8) == *(data.a + 19));     //11  -> 12
    assert(*immediat_superior(&data, STACK_A, data.a + 19) == *(data.a + 13));    //12  -> 13
    assert(*immediat_superior(&data, STACK_A, data.a + 13) == *(data.a + 5));     //13  -> 14
    assert(*immediat_superior(&data, STACK_A, data.a + 5) == *(data.a + 12));     //14  -> 15
    assert(*immediat_superior(&data, STACK_A, data.a + 12) == *(data.a + 18));    //15  -> 16
    assert(*immediat_superior(&data, STACK_A, data.a + 18) == *(data.a + 15));    //16  -> 17
    assert(*immediat_superior(&data, STACK_A, data.a + 15) == *(data.a + 17));    //17  -> 18
    assert(*immediat_superior(&data, STACK_A, data.a + 17) == *(data.a + 11));    //18  -> 19
    assert(*immediat_superior(&data, STACK_A, data.a + 11) == *(data.a + 14));    //19  -> 20
    assert(*immediat_superior(&data, STACK_A, data.a + 14) == *(data.a + 14));    //20  -> 20

    while (data.a)
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
    
        
    /* 9 12 16 18 6 17 20 13 15 19 3 10 11 0 5 14 7 1 2 4 8 */
    assert(*immediat_superior(&data, STACK_B, data.b - 17) == *(data.b - 18));      //1   -> 2
    assert(*immediat_superior(&data, STACK_B, data.b - 18) == *(data.b - 10));     //2   -> 3
    assert(*immediat_superior(&data, STACK_B, data.b - 10) == *(data.b - 19));     //3   -> 4
    assert(*immediat_superior(&data, STACK_B, data.b - 19) == *(data.b - 14));      //4   -> 5    
    assert(*immediat_superior(&data, STACK_B, data.b - 14) == *(data.b - 4));     //5   -> 6
    assert(*immediat_superior(&data, STACK_B, data.b - 4) == *(data.b - 16));     //6   -> 7
    assert(*immediat_superior(&data, STACK_B, data.b - 16) == *(data.b - 20));          //7   -> 8
    assert(*immediat_superior(&data, STACK_B, data.b - 20) == *(data.b));         //8   -> 9
    assert(*immediat_superior(&data, STACK_B, data.b) == *(data.b - 11));     //9   -> 10
    assert(*immediat_superior(&data, STACK_B, data.b - 11) == *(data.b - 12));      //10  -> 11
    assert(*immediat_superior(&data, STACK_B, data.b - 12) == *(data.b - 1));     //11  -> 12
    assert(*immediat_superior(&data, STACK_B, data.b - 1) == *(data.b - 7));    //12  -> 13
    assert(*immediat_superior(&data, STACK_B, data.b - 7) == *(data.b - 15));     //13  -> 14
    assert(*immediat_superior(&data, STACK_B, data.b - 15) == *(data.b - 8));     //14  -> 15
    assert(*immediat_superior(&data, STACK_B, data.b - 8) == *(data.b - 2));    //15  -> 16
    assert(*immediat_superior(&data, STACK_B, data.b - 2) == *(data.b - 5));    //16  -> 17
    assert(*immediat_superior(&data, STACK_B, data.b - 5) == *(data.b - 3));    //17  -> 18
    assert(*immediat_superior(&data, STACK_B, data.b - 3) == *(data.b - 9));    //18  -> 19
    assert(*immediat_superior(&data, STACK_B, data.b - 9) == *(data.b - 6));    //19  -> 20
    assert(*immediat_superior(&data, STACK_B, data.b - 6) == *(data.b - 6));    //20  -> 20  
    ASSERT_END(__func__);
}

int get_borne_assert(int mode)
{
    ASSERT_START(__func__, __LINE__);
	t_global_data data;
	long born[2];
	char *str[] = {"-27809 -28640 -28942 -29464 -30357 -30689 -31084 -31789 -31808 -31811 -32030 -32328 -32553 -32751 -32895 -33320 -33763 -33981 -34318 -32098 -34566 -34866 -35144 -35449 -35845 -36215 -29074 -36452 -36496 -36571 -36940 -36970 -26692 -29312 -29521 -37588 -37783 -38207 -29672 -38665 -38812 -38875 -39148 -39671 -26958 -27155 -32975 -37164 -39676 -37253 -37672 -27968 -39735 -39921 -39926 -40016 -40118 -40282 -34430 -40446 -40899 -41109 -41244 -41364 -24294 -41370 -41490 -41600 -32187 -41937 -41965 -35147 -42142 -21770 -29921 -35561 -42152 -37676 -37850 -38466 -35571 -42231 -42528 -42564 -42662 -42666 -42686 -43017 -43037 -43157 -43330 -43359 -43456 -25821 -43558 -25931 -43644 -43780 -43787 -35657 -43854 -21828 -44122 -44160 -22955 -24828 -44193 -26285 -26584 -30779 -32253 -32513 -44282 -32554 -44387 -44432 -33394 -33461 -35909 -21779 -36159 -44589 -44732 -20658 -36178 -44829 -41308 -41548 -29938 -44988 -38519 -43170 -41553 -45207 -41609 -43264 -45253 -43363 -21468 -44287 -45287 -45500 -23765 -43381 -45581 -45614 -26808 -45753 -44734 -45769 -45863 -23065 -45888 -37070 -37468 -37905 -46011 -46083 -46146 -23865 -26862 -46308 -27356 -46388 -28692 -46419 -46549 -17968 -28961 -44941 -46735 -30181 -46752 -27910 -46802 -38269 -46805 -38300 -38717 -24913 -46917 -24946 -38731 -45125 -46962 -28976 -39206 -39254 -25161 -47026 -47036 -25331 -39523 -46195 -47215 -16992 -47264 -47276 -26073 -47392 -19443 -28263 -28294 -47469 -28989 -46216 -47508 -39533 -47543 -30186 -39946 -45356 -46349 -47568 -47682 -30214 -30890 -47706 -47819 -19457 -31039 -47894 -31123 -47988 -33521 -47834 -48193 -19718 -19807 -48273 -48308 -26177 -20050 -48373 -26495 -26751 -48437 -29326 -20423 -33585 -33614 -30457 -48443 -40499 -33891 -48492 -48523 -40521 -48531 -17106 -48546 -20565 -20711 -40646 -48558 -13206 -48585 -33914 -15652 -34440 -22055 -34473 -48608 -22267 -45367 -23197 -48668 -48858 -23295 -45433 -23473 -48872 -26892 -16461 -26915 -48938 -34549 -20882 -26974 -49001 -34807 -49011 -40809 -49022 -29337 -42222 -29349 -45634 -49036 -30847 -34882 -14121 -27061 -49113 -35015 -35031 -35467 -35664 -27386 -29583 -45790 -35668 -35669 -46463 -14810 -15335 -49135 -15408 -17425 -35940 -17811 -36185 -46598 -49197 -18568 -39558 -18844 -40866 -40905 -41631 -49240 -46902 -9964 -49324 -19049 -12134 -21041 -23657 -23837 -47227 -24093 -27191 -31062 -49365 -17838 -40025 -47391 -47873 -19538 -41687 -27421 -49367 -27857 -31168 -42330 -14446 -25099 -29607 -30856 -47882 -31241 -47941 -14551 -31367 -42457 -49447 -32202 -42474 -49487 -15439 -43273 -19704 -20086 -43305 -49561 -20129 -20222 -32250 -27201 -36270 -43555 -49440 -8444 -21904 -22174 -27363 -28994 -31480 -32804 -8705 -49662 -49767 -10245 -11136 -36330 -16250 -31519 -36340 -31634 -42580 -32909 -49794 -36346 -44303 -7264 -44304 -44312 -11495 -44560 -11641 -17998 -31773 -18267 -45908 -46230 -48603 -49595 -23358 -20294 -23407 -33003 -6420 -33023 -7623 -11878 -49827 -12153 -49837 -7752 -13152 -23879 -13184 -24140 -20321 -33650 -27638 -27891 -47416 -28562 -49840 -32411 -35996 -49885 -13270 -32421 -33127 -34122 -13630 -14139 -18653 -20696 -38423 -8829 -21083 -39590 -23619 -24149 -16287 -16384 -18726 -18824 -40381 -40538 -4013 -9054 -24186 -34827 -12192 -40799 -41993 -29002 -29364 -36673 -42123 -47558 -24339 -13189 -42674 -13289 -25284 -44799 -45185 -4065 -29719 -5077 -5171 -29732 -48655 -9249 -29750 -19153 -5922 -21259 -7664 -14194 -36827 -36973 -38054 -14265 -14520 -45211 -42983 -21390 -43575 -21558 -43744 -15086 -19259 -19273 -1840 -46486 -22203 -48408 -22057 -23660 -24405 -25292 -29928 -2288 -29972 -31826 -31873 -38122 -38391 -2601 -3292 -38534 -9445 -10733 -13352 -13639 -24449 -13757 -24455 -38938 -5710 -7718 -10918 -34173 -35186 -39097 -13746 -14636 -40938 -40998 -44102 -332 -14700 -19709 -24645 -35203 -20576 -3862 -15006 -20673 -45654 -20805 -22417 -45765 -4451 -25521 -35552 -25589 -4536 -6237 -26606 -27383 -6731 -22590 -22736 -27474 -15096 -27918 -35758 -15515 -16472 -36102 -16659 -36337 -46 -16664 -39149 -8043 -39894 -17202 -41357 -64 -41562 -19797 -28224 -28708 -9565 -41828 -4866 -10515 -19924 -10534 -42370 -5312 -10613 -21563 -28773 -28820 -21726 -5366 -22749 -5454 -30187 -6423 -30274 -32437 -11177 -32551 -30337 -39237 -30341 -6480 -6771 -30367 -30942 -13779 -17362 -42997 -17625 -6800 -19941 -75 -22806 -534 -23698 -31918 -31919 -32844 -33283 -605 -612 -40954 -33926 -754 -867 -11690 -20322 -20388 -20824 -913 -20943 -1453 -21073 -23947 -24646 -24747 -25301 -34355 -34400 -34551 -827 -1455 -5499 -6734 -7034 -13845 -36887 -7255 -25850 -27651 -12411 -27803 -28339 -28858 -830 -32611 -831 -13906 -855 -13950 -32871 -13953 -930 -15663 -2381 -15775 -17739 -25860 -42896 -29485 -990 -29490 -32451 -2638 -2975 -7992 -37075 -14333 -14724 -21732 -22207 -22826 -1005 -3251 -23907 -24218 -37220 -1072 -28420 -29998 -1157 -1228 -32893 -8077 -8213 -3307 -35200 -8222 -15827 -1248 -1305 -24226 -30081 -1733 -3910 -3919 -3659 -24386 -29152 -1386 -33386 -8601 -8796 -9497 -15834 -17859 -1419 -1788 -18006 -30738 -18017 -18052 -32457 -20181 -20183 -1434 -35383 -36139 -24534 -1480 -1546 -2463 -3925 -21754 -22326 -26728 -22847 -26746 -1688 -1870 -9881 -26922 -1984 -10109 -10206 -1998 -29275 -30101 -2038 -31072 -2098 -36192 -2169 -2295 -3929 -10936 -25861 -2403 -3972 -34244 -16403 -2419 -4048 -18106 -2441 -11185 -2479 -21106 -11201 -12446 -26500 -26932 -2487 -12618 -2505 -32462 -12774 -2516 -26980 -2746 -3364 -27131 -28089 -28774 -33749 -2811 -3555 -4699 -14032 -2917 -14201 -14770 -14885 -21800 -28892 -5065 -28926 -2932 -3079 -29513 -3198 -3237 -14971 -3366 -21975 -19368 -3690 -19369 -31131 -5580 -5843 -6772 -14989 -22458 -3760 -3762 -7408 -3773 -3775 -7517 -3858 -22905 -15212 -3942 -15308 -15484 -30125 -3960 -7678 -25108 -3993 -10256 -10349 -4062 -19532 -32092 -4067 -25453 -4135 -15959 -4161 -4268 -16017 -16537 -4290 -16576 -4407 -7855 -16990 -4601 -16114 -4734 -18127 -19552 -23004 -29645 -20491 -4761 -24010 -24338 -4947 -5037 -5087 -5299 -5306 -5526 -20703 -6040 -5570 -5760 -24380 -5855 -24879 -7909 -6054 -25465 -6150 -6241 -6268 -8106 -20775 -8257 -21361 -6397 -8522 -11152 -26827 -6449 -11186 -6546 -11261 -21391 -6548 -23079 -6557 -6685 -8909 -6767 -6900 -11645 -6989 -7055 -12792 -7128 -7148 -22093 -7164 -7247 -7363 -7539 -17237 -7710 -17277 -7930 -9058 -7984 -11880 -11997 -26710 -7988 -8135 -12580 -8225 -8285 -12953 -23160 -8564 -8683 -8911 -18375 -13106 -9033 -13503 -9375 -23162 -9728 -10205 -10387 -10408 -19933 -19960 -10422 -10727 -20232 -11076 -11217 -11782 -11800 -23496 -12266 -12344 -12915 -13097 -13159 -13218 -13595 -13239 -13624 -16182 -13628 -13830 -25764 -13939 -13968 -14005 -14117 -14352 -14354 -14451 -14600 -14805 -15316 -15624 -23598 -15728 -16183 -16459 -16481 -16611 -23738 -17142 -17593 -17807 -17926 -18472 -18870 -18942 -19634 -19667 -20063 -20303 -20371 -20836 -21028 -21696", NULL};
	assert(init_global_data(str, &data) == OK);
    int i = 0;
    while (i < data.size_a)
    {
        get_born(born, &data, STACK_A, data.a + i);
        if(mode == DISPLAY)
	        printf("STACK: A index %d value :%d borne left = %ld borne right = %ld\n",i, *(data.a + i), born[LE] , born[RI]);

        assert(born[LE] ==  i);
        assert(born[RI] ==  data.size_a - i);
        i++;
    }
    
    while (data.a)
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
    
    i = 0;
    while (i < data.size_b)
    {
        get_born(born, &data, STACK_B, data.b - i);
        if(mode == DISPLAY)
            printf("STACK: B index %d value :%d borne left = %ld borne right = %ld\n",i, *(data.b - i), born[LE] , born[RI]);
        assert(born[LE] ==  i);
        assert(born[RI] ==  data.size_b - i);
        i++;
    }
    
	return (OK);
    ASSERT_END(__func__);
}

int test(void)
{
    t_global_data data;
    int ranges[1024][2];
    char *str[] = {"--medium -64 -83 -92 -131 -139 -150 -172 -182 -76 -196 -93 -201 -233 -244 -246 -121 -249 -266 -267 -268 -124 -269 -270 -274 8 -276 -179 -280 -300 -12 -303 -1 -321 -180 -185 -323 -325 -327 -335 -28 -336 -122 -342 -345 -369 -130 -186 -371 -221 -281 -283 -375 -377 -379 -382 -19 -383 -136 -384 130 -157 -385 -387 -222 -287 -388 -252 -390 -294 -350 -392 -394 -395 -414 -22 -24 -418 -288 -423 -295 -429 -296 150 -430 -312 -434 -33 142 -313 -435 -442 93 -326 -446 74 46 -66 -356 -449 -78 -82 -450 45 -86 -372 -158 -187 -453 36 -302 -458 -319 -460 -464 -467 30 -99 -373 199 -391 -468 168 159 -190 -206 -404 -472 117 -215 99 -410 -412 28 -475 -478 193 18 -223 -227 -234 -480 -236 -328 -339 192 -378 -380 87 -405 -413 -419 -481 148 48 13 -35 -36 -104 -109 -483 -421 -484 268 -486 144 -40 -43 141 -431 -487 91 -50 -71 -112 42 -113 -437 -137 -488 -164 324 -258 -340 -116 -451 -490 -127 -133 336 -165 228 -491 191 -166 -495 -168 -237 -256 -307 190 -343 392 189 39 -310 388 -497 -393 188 187 -438 175 136 116 -444   -499   79 350 77 72 27 307 -311 115 64 26 -141 -454 7 -177 361 -219 273 245 63 -230 347 282 -173 -324 -232 -238 242 -316 -318 -322 185 -332 -411 113 -462 111 61 38 17 473 240 14 -15 432 -364 236 -17 -29 -72 -73 -415 418 -135 -140 -366 380 435 -144 -181 356 -243 235 227 404 218 186 173 -259 -261 -367 -262 499 397 56 182 -263 12 6 427 4 -46 -376 -146 400 -191 496 352 328 180 165 -192 495 154 153 137 -265 460 106 491 37 3 -31 489 351 488 320 -235 -32 305 272 266 -277 486 171 -290 396 35 34 -53 -60 384 -175 301 132 105 10 490 101 478 -74 -89 487 345 484 341 294 -9 -204 476 472 340 -42 -75 -142 466 -155 465 462 -91 290 -103 459 458 -162 457 220 262 261 216 214 454 453 212 82 206 205 172 -110 449 131 444 443 70 421 411 409 65 -167 442 405 62 32 -13 439 -37 436 -61 434 433 -117 318 431 430 426 -126 315 425 257 167 164 424 254 128 208 54 -63 420 419 416 410 300 163 233 161 408 127 109 407 403 31 29 401 395 393 389 -10 386 383 381 372 369 368 -18 364 363 359 358 243 232 353 202 152 151 349 143 348 342 337 94 89 334 25 207 330 85 327 19 299 298 296 289 287 281 201 198 278 277 274 270 250 124 239 237 217 123 203 196 80 179 178 160 92 75 47",NULL};
    
    assert(init_global_data(str, &data)== OK);
    int nb_range = generate_range(ranges, data.size_a);
    display_range(ranges, nb_range);
    assert(check_range_assert(ranges, data.size_a, nb_range) == OK);
    
    return (OK);
}

int at_beginning_assert(void)
{
    test();
    // min_at_beg_asser();
    // max_at_beg_asser();
    // immediat_superior_assert();
    // get_borne_assert(NO_DISPLAY);
    return (OK);
}