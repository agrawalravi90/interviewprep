## @author Ravi Agrawal
## @date Sep 2014

CC = gcc
SOURCES = common_chars.c
CFLAGS = -Wall -Werror -std=gnu99
EXE = chars

ASCII = a
UTF8 = u8
UTF16 = u16
UTF32 = u32

$(EXE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $<

ascii: $(EXE)
	./$< $(ASCII)

utf8: $(EXE)
	./$< $(UTF8)
	
utf16: $(EXE)
	./$< $(UTF16)

utf32: $(EXE)
	./$< $(UTF32)

clean:
	rm -f *.exe $(EXE)