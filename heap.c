#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {135,
 586,
 222,
 343,
 101,
 336,
 368,
 363,
 261,
 862,
 183,
 205,
 28,
 258,
 129,
 797,
 23,
 67,
 750,
 915,
 35,
 313,
 591,
 666,
 151,
 249,
 519,
 74,
 621,
 84,
 949,
 155,
 146,
 55,
 915,
 394,
 345,
 862,
 997,
 877,
 737,
 930,
 491,
 382,
 64,
 851,
 380,
 659,
 63,
 468,
 190,
 104,
 444,
 500,
 109,
 404,
 878,
 215,
 953,
 91,
 592,
 443,
 803,
 973,
 201,
 962,
 379,
 488,
 972,
 892,
 393,
 396,
 428,
 39,
 416,
 170,
 227,
 236,
 792,
 220,
 972,
 261,
 602,
 408,
 501,
 358,
 442,
 947,
 896,
 127,
 80,
 743,
 70,
 394,
 35,
 518,
 1000,
 825,
 496,
 698,
 750,
 546,
 581,
 800,
 538,
 439,
 636,
 535,
 937,
 31,
 695,
 496,
 869,
 660,
 38,
 309,
 343,
 265,
 459,
 792,
 723,
 10,
 198,
 791,
 231,
 838,
 218,
 569,
 224,
 935,
 86,
 75,
 409,
 201,
 574,
 995,
 827,
 740,
 142,
 31,
 864,
 676,
 276,
 827,
 148,
 326,
 343,
 690,
 532,
 370,
 885,
 722,
 201,
 890,
 565,
 539,
 665,
 26,
 187,
 41,
 484,
 129,
 387,
 214,
 22,
 765,
 790,
 611,
 767,
 321,
 734,
 313,
 828,
 210,
 185,
 605,
 297,
 309,
 873,
 140,
 103,
 944,
 788,
 538,
 250,
 104,
 860,
 907,
 28,
 579,
 611,
 128,
 720,
 632,
 578,
 957,
 510,
 2,
 582,
 404,
 77,
 361,
 943,
 280,
 885,
 5,
 312,
 817,
 292,
 722,
 12,
 738,
 187,
 194,
 722,
 462,
 152,
 108,
 800,
 573,
 417,
 387,
 198,
 501,
 939,
 0,
 770,
 255,
 438,
 213,
 487,
 193,
 479,
 553,
 369,
 482,
 501,
 165,
 554,
 319,
 886,
 9,
 768,
 872,
 219,
 952,
 467,
 703,
 40,
 706,
 924,
 259,
 132,
 523,
 747,
 928,
 138,
 76,
 68,
 188,
 864,
 640,
 264,
 68,
 811,
 401,
 572,
 368,
 205,
 611,
 447,
 110,
 86,
 913,
 664,
 860,
 272,
 990,
 813,
 129,
 8,
 1000,
 496,
 244,
 598,
 99,
 701,
 439,
 962,
 560,
 228,
 444,
 299,
 56,
 993,
 588,
 361,
 33,
 978,
 585,
 995,
 593,
 991,
 48,
 566,
 850,
 430,
 503,
 388,
 682,
 904,
 464,
 417,
 9,
 148,
 759,
 528,
 170,
 963,
 650,
 652,
 364,
 165,
 348,
 180,
 146,
 223,
 121,
 575,
 322,
 891,
 950,
 283,
 561,
 652,
 599,
 961,
 291,
 54,
 680,
 231,
 971,
 805,
 605,
 39,
 943,
 449,
 384,
 842,
 423,
 828,
 850,
 976,
 106,
 882,
 82,
 630,
 860,
 839,
 411,
 303,
 227,
 691,
 654,
 801,
 345,
 456,
 71,
 657,
 568,
 137,
 532,
 734,
 22,
 67,
 856,
 876,
 237,
 492,
 942,
 626,
 238,
 127,
 201,
 920,
 640,
 371,
 568,
 24,
 735,
 705,
 452,
 138,
 858,
 794,
 916,
 584,
 916,
 570,
 516,
 458,
 69,
 565,
 662,
 871,
 784,
 161,
 371,
 245,
 439,
 683,
 59,
 101,
 215,
 21,
 126,
 672,
 516,
 65,
 838,
 681,
 672,
 634,
 963,
 783,
 354,
 460,
 737,
 880,
 186,
 664,
 948,
 537,
 228,
 304,
 324,
 997,
 367,
 146,
 387,
 750,
 848,
 757,
 89,
 745,
 499,
 703,
 528,
 592,
 214,
 402,
 352,
 105,
 545,
 408,
 675,
 205,
 100,
 288,
 178,
 607,
 172,
 446,
 320,
 83,
 587,
 178,
 932,
 551,
 329,
 976,
 504,
 237,
 676,
 119,
 170,
 813,
 838,
 676,
 739,
 175,
 995,
 982,
 731,
 153,
 607,
 209,
 195,
 767,
 660,
 18,
 641,
 380,
 564,
 725,
 81,
 132,
 9,
 693,
 593,
 583,
 40,
 893,
 649,
 278,
 530,
 858,
 44,
 1000,
 804,
 260,
 732,
 882,
 171,
 400,
 272,
 772,
 20,
 309,
 622,
 552,
 899,
 66,
 320,
 529,
 310,
 4,
 577,
 346,
 761,
 95,
 470,
 855,
 229,
 681,
 949,
 222,
 556,
 996,
 106,
 696,
 840,
 776,
 992,
 182,
 1000,
 763,
 321,
 398,
 894,
 910,
 344,
 334,
 437,
 606,
 819,
 332,
 215,
 114,
 898,
 966,
 745,
 391,
 925,
 665,
 24,
 971,
 9,
 351,
 445,
 30,
 178,
 34,
 258,
 431,
 523,
 306,
 999,
 452,
 155,
 94,
 234,
 476,
 784,
 404,
 28,
 173,
 414,
 273,
 149,
 736,
 269,
 609,
 408,
 783,
 610,
 364,
 407,
 196,
 855,
 417,
 485,
 468,
 788,
 578,
 218,
 573,
 316,
 224,
 329,
 654,
 163,
 432,
 228,
 678,
 840,
 424,
 13,
 792,
 757,
 113,
 185,
 655,
 680,
 423,
 514,
 556,
 903,
 159,
 816,
 564,
 843,
 209,
 862,
 734,
 746,
 337,
 303,
 260,
 680,
 106,
 47,
 453,
 243,
 942,
 225,
 141,
 400,
 643,
 178,
 930,
 934,
 218,
 321,
 572,
 442,
 34,
 205,
 223,
 842,
 203,
 357,
 595,
 982,
 500,
 710,
 149,
 196,
 137,
 208,
 548,
 891,
 691,
 237,
 853,
 800,
 660,
 904,
 67,
 908,
 329,
 378,
 352,
 541,
 528,
 177,
 161,
 312,
 610,
 455,
 631,
 251,
 345,
 402,
 777,
 18,
 178,
 151,
 975,
 885,
 184,
 489,
 468,
 335,
 934,
 600,
 581,
 698,
 313,
 546,
 763,
 642,
 239,
 492,
 737,
 334,
 134,
 896,
 927,
 968,
 174,
 208,
 874,
 612,
 114,
 389,
 381,
 126,
 340,
 177,
 124,
 259,
 476,
 457,
 469,
 742,
 911,
 377,
 924,
 702,
 131,
 96,
 325,
 195,
 605,
 425,
 232,
 579,
 972,
 200,
 106,
 313,
 651,
 95,
 21,
 61,
 530,
 955,
 270,
 459,
 976,
 911,
 587,
 837,
 57,
 346,
 199,
 18,
 311,
 103,
 39,
 978,
 870,
 834,
 716,
 867,
 998,
 443,
 820,
 732,
 973,
 716,
 951,
 12,
 61,
 887,
 338,
 312,
 405,
 225,
 625,
 365,
 966,
 786,
 767,
 333,
 310,
 832,
 208,
 115,
 891,
 429,
 781,
 228,
 675,
 327,
 932,
 625,
 245,
 521,
 28,
 307,
 284,
 202,
 208,
 676,
 582,
 72,
 97,
 603,
 107,
 158,
 730,
 43,
 25,
 152,
 115,
 998,
 338,
 49,
 75,
 530,
 628,
 39,
 514,
 937,
 660,
 299,
 440,
 223,
 485,
 609,
 109,
 849,
 397,
 506,
 12,
 846,
 731,
 515,
 394,
 937,
 49,
 308,
 763,
 291,
 378,
 416,
 109,
 997,
 989,
 798,
 194,
 687,
 940,
 556,
 47,
 607,
 233,
 686,
 147,
 745,
 355,
 163,
 77,
 448,
 548,
 770,
 339,
 930,
 51,
 722,
 694,
 886,
 104,
 766,
 527,
 597,
 653,
 923,
 947,
 326,
 949,
 543,
 86,
 190,
 459,
 388,
 650,
 881,
 668,
 858,
 958,
 256,
 658,
 274,
 143,
 148,
 756,
 538,
 564,
 787,
 502,
 84,
 738,
 204,
 910,
 976,
 441,
 970,
 713,
 335,
 500,
 364,
 728,
 789,
 699,
 777,
 190,
 240,
 562,
 314,
 566,
 746,
 216,
 852,
 707,
 848,
 117,
 660,
 29,
 96,
 150,
 268,
 250,
 52,
 569,
 512,
 792,
 129,
 958,
 86,
 713,
 416,
 239,
 110,
 704,
 80,
 583,
 700,
 967,
 956,
 84,
 832,
 26,
 415,
 835,
 132,
 299,
 54,
 186,
 242,
 422,
 762,
 13,
 239,
 850,
 582,
 521,
 672,
 908,
 481,
 831,
 724,
 502,
 658,
 667,
 731,
 227,
 697,
 980,
 314,
 164,
 945,
 443,
 232,
 564,
 322,
 715,
 299};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Array setelah sorting:\n");
    printArray(arr, n);

    return 0;
}
