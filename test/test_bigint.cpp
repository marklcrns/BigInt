#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "bigint.h"


SCENARIO("Increment/Decrement operator overloads") {
  GIVEN("Positive BigInt") {

    WHEN ("BigInt > 0") {
      BigInt num(4);
      REQUIRE(num == 4);

      THEN("Where num = 4, ++num == 5") {
        ++num;
        CHECK(num == 5);
      }

      THEN("Where num = 4, num++ == 4, then num == 5") {
        CHECK(num++ == 4);
        CHECK(num == 5);
      }

      THEN("Where num = 4, --num == 5") {
        --num;
        CHECK(num == 3);
      }

      THEN("Where num = 4, num-- == 4, then num == 3") {
        CHECK(num-- == 4);
        CHECK(num == 3);
      }

    }

    WHEN ("BigInt == 0") {
      BigInt num(0);
      REQUIRE(num == 0);

      THEN("Where num = 0, ++num == 1") {
        ++num;
        CHECK(num == 1);
      }

      THEN("Where num = 0, num++ == 0, then num == 1") {
        CHECK(num++ == 0);
        CHECK(num == 1);
      }

      THEN("Where num = 0, --num == -1") {
        --num;
        CHECK(num == -1);
      }

      THEN("Where num = 0, num-- == 0, then num == -1") {
        CHECK(num-- == 0);
        CHECK(num == -1);
      }

    }

    WHEN ("BigInt < -1") {
      BigInt num(-1);
      REQUIRE(num == -1);

      THEN("Where num = -1, ++num == 0") {
        ++num;
        CHECK(num == 0);
      }

      THEN("Where num = -1, num++ == -1, then num == 0") {
        CHECK(num++ == -1);
        CHECK(num == 0);
      }

      THEN("Where num = -1, --num == -2") {
        --num;
        CHECK(num == -2);
      }

      THEN("Where num = -1, num-- == -1, then num == -2") {
        CHECK(num-- == -1);
        CHECK(num == -2);
      }

    }

  }
}

SCENARIO("BigInt Comparison operator overloads") {

  GIVEN("Two positive BigInt") {

    WHEN("a = 4 and b = 2") {
      BigInt a(4);
      BigInt b(2);

      REQUIRE(a == 4);
      REQUIRE(b == 2);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a < b is false")  { CHECK((a < b) == false); }
      THEN("a > b is true")   { CHECK((a > b) == true); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is false") { CHECK((a <= b) == false); }
      THEN("a >= b is true")  { CHECK((a >= b) == true); }
    }

    WHEN("a = 7 and b = 74") {
      BigInt a(7);
      BigInt b(74);

      REQUIRE(a == 7);
      REQUIRE(b == 74);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a < b is true")   { CHECK((a < b) == true); }
      THEN("a > b is false")  { CHECK((a > b) == false); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is true")  { CHECK((a <= b) == true); }
      THEN("a >= b is false") { CHECK((a >= b) == false); }
    }

    WHEN("a = 999 and b = 999") {
      BigInt a(999);
      BigInt b(999);

      REQUIRE(a == 999);
      REQUIRE(b == 999);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a < b is false") { CHECK((a < b) == false); }
      THEN("a > b is false") { CHECK((a > b) == false); }
      THEN("a == b is true") { CHECK((a == b) == true); }
      THEN("a <= b is true") { CHECK((a <= b) == true); }
      THEN("a >= b is true") { CHECK((a >= b) == true); }
    }

  }

  GIVEN("One positive BigInt and one negative BigInt") {

    WHEN("a = -4 and b = 2") {
      BigInt a(-4);
      BigInt b(2);

      REQUIRE(a == -4);
      REQUIRE(b == 2);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == true);

      THEN("a < b is true")   { CHECK((a < b) == true); }
      THEN("a > b is false")  { CHECK((a > b) == false); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is true")  { CHECK((a <= b) == true); }
      THEN("a >= b is false") { CHECK((a >= b) == false); }
    }

    WHEN("a = 4 and b = -2") {
      BigInt a(4);
      BigInt b(-2);

      REQUIRE(a == 4);
      REQUIRE(b == -2);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == false);

      THEN("a < b is false")  { CHECK((a < b) == false); }
      THEN("a > b is true")   { CHECK((a > b) == true); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is false") { CHECK((a <= b) == false); }
      THEN("a >= b is true")  { CHECK((a >= b) == true); }
    }

    WHEN("a = -999 and b = 999") {
      BigInt a(-999);
      BigInt b(999);

      REQUIRE(a == -999);
      REQUIRE(b == 999);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == true);

      THEN("a < b is true")   { CHECK((a < b) == true); }
      THEN("a > b is false")  { CHECK((a > b) == false); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is true")  { CHECK((a <= b) == true); }
      THEN("a >= b is false") { CHECK((a >= b) == false); }
    }

    WHEN("a = 999 and b = -999") {
      BigInt a(999);
      BigInt b(-999);

      REQUIRE(a == 999);
      REQUIRE(b == -999);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == false);

      THEN("a < b is false")  { CHECK((a < b) == false); }
      THEN("a > b is true")   { CHECK((a > b) == true); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is false") { CHECK((a <= b) == false); }
      THEN("a >= b is true")  { CHECK((a >= b) == true); }
    }
  }

  GIVEN("Two negative BigInt") {

    WHEN("a = -4 and b = -2") {
      BigInt a(-4);
      BigInt b(-2);

      REQUIRE(a == -4);
      REQUIRE(b == -2);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == false);

      THEN("a < b is true")   { CHECK((a < b) == true); }
      THEN("a > b is false")  { CHECK((a > b) == false); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is true")  { CHECK((a <= b) == true); }
      THEN("a >= b is false") { CHECK((a >= b) == false); }
    }

    WHEN("a = -7 and b = -74") {
      BigInt a(-7);
      BigInt b(-74);

      REQUIRE(a == -7);
      REQUIRE(b == -74);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == false);

      THEN("a < b is false")  { CHECK((a < b) == false); }
      THEN("a > b is true")   { CHECK((a > b) == true); }
      THEN("a == b is false") { CHECK((a == b) == false); }
      THEN("a <= b is false") { CHECK((a <= b) == false); }
      THEN("a >= b is true")  { CHECK((a >= b) == true); }
    }

    WHEN("a = -999 and b = -999") {
      BigInt a(-999);
      BigInt b(-999);

      REQUIRE(a == -999);
      REQUIRE(b == -999);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == false);

      THEN("a < b is false") { CHECK((a < b) == false); }
      THEN("a > b is false") { CHECK((a > b) == false); }
      THEN("a == b is true") { CHECK((a == b) == true); }
      THEN("a <= b is true") { CHECK((a <= b) == true); }
      THEN("a >= b is true") { CHECK((a >= b) == true); }
    }
  }

}


SCENARIO("BigInt Arithmetic operator overloads") {

  GIVEN("Two positive BigInt") {

    WHEN("a = 1 and b = 2") {
      BigInt a(1);
      BigInt b(2);

      REQUIRE(a == 1);
      REQUIRE(b == 2);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 1") { CHECK((a ^ b) == 1); }
      THEN("a * b = 2")  { CHECK((a * b) == 2); }
      THEN("a / b = 1")  { CHECK((a / b) == 1); }
      THEN("a % b = 1")  { CHECK((a % b) == 1); }
      THEN("a + b = 3")  { CHECK((a + b) == 3); }
      THEN("a - b = -1")  { CHECK((a - b) == -1); }
    }

    WHEN("a = 4 and b = 2") {
      BigInt a(4);
      BigInt b(2);

      REQUIRE(a == 4);
      REQUIRE(b == 2);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 16") { CHECK((a ^ b) == 16); }
      THEN("a * b = 8")  { CHECK((a * b) == 8); }
      THEN("a / b = 2")  { CHECK((a / b) == 2); }
      THEN("a % b = 0")  { CHECK((a % b) == 0); }
      THEN("a + b = 6")  { CHECK((a + b) == 6); }
      THEN("a - b = 2")  { CHECK((a - b) == 2); }
    }

    WHEN("a = 1 and b = 7") {
      BigInt a(1);
      BigInt b(7);

      REQUIRE(a == 1);
      REQUIRE(b == 7);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 1")  { CHECK((a ^ b) == 1); }
      THEN("a * b = 7")  { CHECK((a * b) == 7); }
      THEN("a + b = 8")  { CHECK((a + b) == 8); }
      THEN("a - b = -6") { CHECK((a - b) == -6); }
    }

    WHEN("a = 7 and b = 1") {
      BigInt a(7);
      BigInt b(1);

      REQUIRE(a == 7);
      REQUIRE(b == 1);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 7") { CHECK((a ^ b) == 7); }
      THEN("a * b = 7") { CHECK((a * b) == 7); }
      THEN("a / b = 7") { CHECK((a / b) == 7); }
      THEN("a % b = 0") { CHECK((a % b) == 0); }
      THEN("a + b = 8") { CHECK((a + b) == 8); }
      THEN("a - b = 6") { CHECK((a - b) == 6); }
    }

    WHEN("a = 3 and b = 0") {
      BigInt a(3);
      BigInt b(0);

      REQUIRE(a == 3);
      REQUIRE(b == 0);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 1")      { CHECK((a ^ b) == 1); }
      THEN("a * b = 0")      { CHECK((a * b) == 0); }
      THEN("a / b = #DIV/0") { CHECK((a / b) == "#DIV/0"); }
      THEN("a + b = 3")      { CHECK((a + b) == 3); }
      THEN("a - b = 3")      { CHECK((a - b) == 3); }
    }

    WHEN("a = 0 and b = 10") {
      BigInt a(0);
      BigInt b(10);

      REQUIRE(a == 0);
      REQUIRE(b == 10);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 0")   { CHECK((a ^ b) == 0); }
      THEN("a * b = 0")   { CHECK((a * b) == 0); }
      THEN("a / b = 0")   { CHECK((a / b) == 0); }
      THEN("a % b = 0")   { CHECK((a % b) == 0); }
      THEN("a + b = 10")  { CHECK((a + b) == 10); }
      THEN("a - b = -10") { CHECK((a - b) == -10); }
    }

    WHEN("a = 99999 and b = 123") {
      BigInt a("99999");
      BigInt b("123");

      REQUIRE(a == 99999);
      REQUIRE(b == 123);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 998770749997469764697109293927434765222072839257725452373098099569770602312708940832265734923699294216327218368757396279114702653389078614376903746652848161545235017649748473875101780205368216807329548593738252272128575002638150536488969749663335100719523173702357203992025228405955675024881518155019866589456001047673538474948119001878447034812840812655081419347852983145237858414047850396268098879711039088506332907459316030529433234843285589711292156006682758262154723484744155482773226467064555280965580135381054715817437837330915426209793246927110032445794367456637780981144798078713032137302620924970012299999") {
        CHECK((a ^ b) == "998770749997469764697109293927434765222072839257725452373098099569770602312708940832265734923699294216327218368757396279114702653389078614376903746652848161545235017649748473875101780205368216807329548593738252272128575002638150536488969749663335100719523173702357203992025228405955675024881518155019866589456001047673538474948119001878447034812840812655081419347852983145237858414047850396268098879711039088506332907459316030529433234843285589711292156006682758262154723484744155482773226467064555280965580135381054715817437837330915426209793246927110032445794367456637780981144798078713032137302620924970012299999");
      }
      THEN("a * b = 12299877") { CHECK((a * b) == "12299877"); }
      THEN("a / b = 813")      { CHECK((a / b) == "813"); }
      THEN("a % b = 0")        { CHECK((a % b) == "0"); }
      THEN("a + b = 100122")   { CHECK((a + b) == "100122"); }
      THEN("a - b = 99876")    { CHECK((a - b) == "99876"); }
    }
  }

  GIVEN("One positive BigInt and one negative BigInt") {

    WHEN ("a = 4 and b = -2") {
      BigInt a(4);
      BigInt b(-2);

      REQUIRE(a == 4);
      REQUIRE(b == -2);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")       { CHECK((a ^ b) == 0); }
      THEN("a * b = -8")      { CHECK((a * b) == -8); }
      THEN("a / b = -2")      { CHECK((a / b) == -2); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a - b = 6")       { CHECK((a - b) == 6); }
      THEN("a + b = 2")       { CHECK((a + b) == 2); }
    }

    WHEN ("a = -2 and b = 4") {
      BigInt a(-2);
      BigInt b(4);

      REQUIRE(a == -2);
      REQUIRE(b == 4);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 16") { CHECK((a ^ b) == 16); }
      THEN("a * b = -8") { CHECK((a * b) == -8); }
      THEN("a / b = -1")  { CHECK((a / b) == -1); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = 2")  { CHECK((a + b) == 2); }
      THEN("a - b = -6") { CHECK((a - b) == -6); }
    }

    WHEN("a = 0 and b = -7") {
      BigInt a(0);
      BigInt b(-7);

      REQUIRE(a == 0);
      REQUIRE(b == -7);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")  { CHECK((a ^ b) == 0); }
      THEN("a * b = 0")  { CHECK((a * b) == 0); }
      THEN("a / b = 0")  { CHECK((a / b) == 0); }
      THEN("a + b = -7") { CHECK((a + b) == -7); }
      THEN("a - b = 7")  { CHECK((a - b) == 7); }
    }

    WHEN("a = -8 and b = 0") {
      BigInt a(-8);
      BigInt b(0);

      REQUIRE(a == -8);
      REQUIRE(b == 0);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 1")      { CHECK((a ^ b) == 1); }
      THEN("a * b = 0")      { CHECK((a * b) == 0); }
      THEN("a / b = #DIV/0") { CHECK((a / b) == "#DIV/0"); CHECK((a / b).is_valid() == false); }
      THEN("a + b = -8")     { CHECK((a + b) == -8); }
      THEN("a - b = -8")     { CHECK((a - b) == -8); }
    }

    WHEN("a = 99999 and b = -123") {
      BigInt a("99999");
      BigInt b("-123");

      REQUIRE(a == 99999);
      REQUIRE(b == -123);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")        { CHECK((a ^ b) == 0); }
      THEN("a * b = 12299877") { CHECK((a * b) == "-12299877"); }
      THEN("a / b = -813")     { CHECK((a / b) == "-813"); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = 99876")    { CHECK((a + b) == "99876"); }
      THEN("a - b = 100122")   { CHECK((a - b) == "100122"); }
    }

    WHEN("a = -99999 and b = 123") {
      BigInt a("-99999");
      BigInt b("123");

      REQUIRE(a == -99999);
      REQUIRE(b == 123);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = -998770749997469764697109293927434765222072839257725452373098099569770602312708940832265734923699294216327218368757396279114702653389078614376903746652848161545235017649748473875101780205368216807329548593738252272128575002638150536488969749663335100719523173702357203992025228405955675024881518155019866589456001047673538474948119001878447034812840812655081419347852983145237858414047850396268098879711039088506332907459316030529433234843285589711292156006682758262154723484744155482773226467064555280965580135381054715817437837330915426209793246927110032445794367456637780981144798078713032137302620924970012299999") {
        CHECK((a ^ b) == "-998770749997469764697109293927434765222072839257725452373098099569770602312708940832265734923699294216327218368757396279114702653389078614376903746652848161545235017649748473875101780205368216807329548593738252272128575002638150536488969749663335100719523173702357203992025228405955675024881518155019866589456001047673538474948119001878447034812840812655081419347852983145237858414047850396268098879711039088506332907459316030529433234843285589711292156006682758262154723484744155482773226467064555280965580135381054715817437837330915426209793246927110032445794367456637780981144798078713032137302620924970012299999");
      }
      THEN("a * b = -12299877") { CHECK((a * b) == "-12299877"); }
      THEN("a / b = -813")      { CHECK((a / b) == "-813"); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = -99876")    { CHECK((a + b) == "-99876"); }
      THEN("a - b = -100122")   { CHECK((a - b) == "-100122"); }
    }

  }


  GIVEN("Two negative BigInt") {

    WHEN("a = -4 and b = -2") {
      BigInt a(-4);
      BigInt b(-2);

      REQUIRE(a == -4);
      REQUIRE(b == -2);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")  { CHECK((a ^ b) == 0); }
      THEN("a * b = 8")  { CHECK((a * b) == 8); }
      THEN("a / b = 2")  { CHECK((a / b) == 2); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = -6") { CHECK((a + b) == -6); }
      THEN("a - b = -2") { CHECK((a - b) == -2); }
    }

    WHEN("a = -1 and b = -7") {
      BigInt a(-1);
      BigInt b(-7);

      REQUIRE(a == -1);
      REQUIRE(b == -7);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")  { CHECK((a ^ b) == 0); }
      THEN("a * b = 7")  { CHECK((a * b) == 7); }
      THEN("a / b = 0")  { CHECK((a / b) == 0); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = -8") { CHECK((a + b) == -8); }
      THEN("a - b = 6")  { CHECK((a - b) == 6); }
    }

    WHEN("a = -7 and b = -1") {
      BigInt a(-7);
      BigInt b(-1);

      REQUIRE(a == -7);
      REQUIRE(b == -1);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")  { CHECK((a ^ b) == 0); }
      THEN("a * b = 7")  { CHECK((a * b) == 7); }
      THEN("a / b = 7")  { CHECK((a / b) == 7); }
      THEN("a + b = -8") { CHECK((a + b) == -8); }
      THEN("a - b = -6") { CHECK((a - b) == -6); }
    }

    WHEN("a = -3 and b = -0") {
      BigInt a("-3");
      BigInt b("-0");

      REQUIRE(a == -3);
      REQUIRE(b == 0);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == true);

      THEN("a ^ b = 1")      { CHECK((a ^ b) == 1); }
      THEN("a * b = 0")      { CHECK((a * b) == 0); }
      THEN("a / b = #DIV/0") { CHECK((a / b) == "#DIV/0"); CHECK((a / b).is_valid() == false); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = -3")     { CHECK((a + b) == -3); }
      THEN("a - b = -3")     { CHECK((a - b) == -3); }
    }

    WHEN("a = -0 and b = -10") {
      BigInt a("-0");
      BigInt b("-10");

      REQUIRE(a == 0);
      REQUIRE(b == -10);
      REQUIRE(a.is_positive() == true);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")   { CHECK((a ^ b) == 0); }
      THEN("a * b = 0")   { CHECK((a * b) == 0); }
      THEN("a / b = 0")   { CHECK((a / b) == 0); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = -10") { CHECK((a + b) == -10); }
      THEN("a - b = 10")  { CHECK((a - b) == 10); }
    }

    WHEN("a = -99999 and b = -123") {
      BigInt a("-99999");
      BigInt b("-123");

      REQUIRE(a == -99999);
      REQUIRE(b == -123);
      REQUIRE(a.is_positive() == false);
      REQUIRE(b.is_positive() == false);

      THEN("a ^ b = 0")        { CHECK((a ^ b) == 0); }
      THEN("a * b = 12299877") { CHECK((a * b) == "12299877"); }
      THEN("a / b = 813")      { CHECK((a / b) == "813"); }
      THEN("a % b = #DOMAIN") { CHECK((a % b) == "#DOMAIN"); CHECK((a % b).is_valid() == false); }
      THEN("a + b = -100122")  { CHECK((a + b) == "-100122"); }
      THEN("a - b = -99876")   { CHECK((a - b) == "-99876"); }
    }

  }
}

SCENARIO("BigInt in scientific notation test") {

  GIVEN("Positive BigInt") {
    BigInt a("9999999");
    size_t width = 3;
    REQUIRE(a == "9999999");
    REQUIRE(a.is_positive() == true);

    THEN("Calling to_scientific() with width of 3") {
      CHECK(a.to_scientific(width) == "999e+4");
    }
  }

  GIVEN("Negative BigInt") {
    BigInt a("-9999999");
    size_t width = 3;
    REQUIRE(a == "-9999999");
    REQUIRE(a.is_positive() == false);

    THEN("Calling to_scientific() with width of 3") {
      CHECK(a.to_scientific(width) == "-999e+4");
    }
  }
}

