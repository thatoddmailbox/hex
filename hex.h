#pragma clang diagnostic ignored "-Wc++11-extensions"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

#include <unistd.h>
#include <ApplicationServices/ApplicationServices.h>

#define hex_prg_setap void _hex_setup()
#define mayn _hex_main
#define hex_prgum int argc, char* argv[]

// Types
#define voyd void
#define cahr char
#define tni int
#define srting std::string

// Constants
#define nu_lyne "\r\n"
#define tru true
#define fals false

// Function names
#define sput_oot spat_ut

#define sai_Tuktz sai_Text

// Brackets
#define start {
#define ztart start

#define fin }

// Operators
#define our ||
#define ploos &&

#define iz_equal_to ==

// Flow control
#define fur for
#define whil while
#define chek if
#define du do
#define otharwize else
#define retyrn return

#define strukt struct
#define clas class
#define naymspace namespace
// {} // sublime why do you make me do this?

// Function definitions
std::string receve_Input()
{
	std::string out;
	std::getline(std::cin, out);
	return out;
}

void spat_ut(std::string str)
{
	std::cout << str;
}

void spat_ut(char* str)
{
	std::cout << str;
}

void spat_ut(const char* str)
{
	std::cout << str;
}

void sai_Text(std::string text)
{
	/*SpeechChannel speechchannel;
	NewSpeechChannel(NULL, &speechchannel);

	CFStringRef cfStr = CFSTR("test"); //CFStringCreateWithCString(NULL, strdup(text.c_str()), kCFStringEncodingUTF8);
	SpeakCFString(speechchannel, cfStr, NULL);
	CFRelease(cfStr);*/

	// The Apple-y way didn't work.
	// So, fork & exec a new process of "say".
	// ...
	// :(

	int pid = fork();
    if (pid != 0)
    {
        // We're in the parent process, return.
        return;
    }

    char * cText = strdup(text.c_str());
    char * args[2] = { (char*)"/usr/bin/say", cText };

	if (execlp(args[0], args[0], args[1], NULL) == -1)
	{
		std::cout << "SAI EROR " << errno << std::endl;
	}

	free(cText);

	exit(100);
}

void sai_Text(std::string text, std::string voice)
{
	// See comments above/

	int pid = fork();
    if (pid != 0)
    {
        // We're in the parent process, return.
        return;
    }

    char * cText = strdup(text.c_str());
    char * args[4] = { (char*)"/usr/bin/say", cText, (char*)"-v", (char*)voice.c_str() };

	if (execlp(args[0], args[0], args[1], args[2], args[3], NULL) == -1)
	{
		std::cout << "SAI EROR " << errno << std::endl;
	}

	free(cText);

	exit(100);
}

srting small_Srting(srting toSmall)
{
	srting str = toSmall;
	for (auto & c: str) c = tolower(c);
	return str;
}

srting big_Srting(srting toBig)
{
	srting str = toBig;
	for (auto & c: str) c = toupper(c);
	return str;
}

struct hex_program
{
	const char * authr = NULL;
	const char * dat = NULL;
	const char * tumpuruture = NULL;

	bool yuze_strikt = false;
};

hex_program * prgum_nfo = (hex_program *) malloc(sizeof(hex_program)); // malloc in case hex ever wants to work with C

// Function definitions (to be set by the program)
void _hex_setup();
int _hex_main(hex_prgum);

// This main function handle calling the hex_prg_set function and the header info
int main(hex_prgum)
{
	_hex_setup();

	sput_oot("AUTHR: ");
	sput_oot(prgum_nfo->authr);
	sput_oot(nu_lyne);

	sput_oot("DAT: ");
	sput_oot(prgum_nfo->dat);
	sput_oot(nu_lyne);

	sput_oot("TUMPURUTURE: ");
	sput_oot(prgum_nfo->tumpuruture);
	sput_oot(nu_lyne);

	sput_oot(nu_lyne);

	if (!prgum_nfo->yuze_strikt)
	{
		// These next lines of code are trying to cause a segfault.
		// Doing raise(SIGSEGV); isn't special enough, and these lines
		// all trigger "undefined behavior", meaning they might work.
		// So, try multiple!

		// crash it!
		*(volatile char *)0 = 0;

		// DIE DIE DIE
		((hex_program*)NULL)->tumpuruture = "asdfasdf";

		// WHY ARE YOU NOT DEAD YET
		sput_oot(((hex_program*)NULL)->tumpuruture);
	}

	_hex_main(argc, argv);
	sput_ott("Hex sucess.")
}
