#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int total, n;
string input;
int v [1000];

int main()
{
	cin >> n >> input;
	for (char x : input)
	{
		if (!v [x])
			total++;
		v [x] = 1;
	}

	memset (v,
          0, sizeof v);
	int solution = 200100, currentCount = 0, current = 0;

	for (int i = 0; i < n; i++)
	{
		if (!v [input [i]])
			currentCount++;

		v [input [i]]++;

		if (total == currentCount)
			solution = min (solution, i - current + 1);

		while (total == currentCount && current < i)
		{
			solution = min (solution, i - current + 1);

			if (v [input [current]] - 1 == 0)
				currentCount--;

			v [input [current]]--;
			current++;
		}
	}

	cout << solution << endl;

	return 0;
}


/*
37
11112222333123334512345555123345612345

2. place Drzavno takmicenje iz informatike 2014 (razigravanje)
2. place Drzavno takmicenje iz informatike 2015

Participated in the 2011 junior Balkan Olympiad in Informatics in Bistrita, Romania.
Participated in the 2013 Balkan Olympiad in Informatics in Sarajevo, Bosnia and Herzegovina
Bronze medal at the 2014 Balkan Olympiad in Informatics in Ankara, Turkey
Participated in the 2015 Balkan Olympiad in Informatics in Ruse, Bulgaria

Participated in the 2014 International Olympiad in Informatics in Taipei, Taiwan
Participated in the 2015 International Olympiad in Informatics in Almaty, Khazakstan

Participated in the 24-hour IEEEXtreme 9.0 team programming competition http://www.ieee.org/membership_services/membership/students/competitions/xtreme/index.html (ranked top100, team name: SarajevoDragons, though I am unable to find the ranking list online so you will unfortunately have to take my word for it).

codeforces profile: http://www.codeforces.com/profile/elvircrn

More information about the type and format about the aforementioned competitions: https://en.wikipedia.org/wiki/Competitive_programming

Participated at the 2016 Elektrijada in Rimini, Italy (oblasti: informatika i objektno orijentisano programiranje);

I did not attend any programming summer schools, however, I did hold lectures as a part of my commitment to BHOI:

Lecturer at the "IV BHOI C++ Zimski Kamp - 2016 godina", github of my lecture: https://github.com/BHOI/BHOI-Sekcije-i-Kampovi/tree/master/Januarski%20Kamp/Dan%203

Lecturer at the "BHOI napredna sekcija": https://github.com/BHOI/BHOI-Sekcije-i-Kampovi/tree/master/Sekcije (2016)

Problem setter at the " 2016 juniorsko BHOI drzavno takmicenje iz informatike" and "BHOI dravno takmicenje": https://github.com/BHOI/BHOI-takmicenja-iz-informatike/tree/master/BHOI%202016

Held a lecture as a part of preparation for the BiH high school team for the Balkan Olympiad in informatics; https://github.com/BHOI/BHOI-Sekcije-i-Kampovi/tree/master/Pripreme%20za%20BOI%20kamp
*/
