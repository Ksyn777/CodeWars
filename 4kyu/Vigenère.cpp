#include <string>
#include <codecvt>
#include <locale>

using namespace std;

class VigenèreCipher {
public:

    string key;
    string alphabet;

    VigenèreCipher() {}

    u32string to_u32(const string& s) {
        if (s.empty()) return U"";
        wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
        return conv.from_bytes(s);
    }

    string from_u32(const u32string& s) {
        wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
        return conv.to_bytes(s);
    }

    string encode(string str) {
        u32string u_str = to_u32(str);
        u32string u_abc = to_u32(alphabet);
        u32string u_key = to_u32(key);
        u32string result = U"";

        for (size_t i = 0; i < u_str.length(); i++) {
            size_t index_t = u_abc.find(u_str[i]);
            size_t index_k = u_abc.find(u_key[i % u_key.length()]);

            if (index_t != u32string::npos) {
                int shift = (index_k == u32string::npos) ? 0 : (int)index_k;
                result += u_abc[(index_t + shift) % u_abc.length()];
            } else {
                result += u_str[i];
            }
        }
        return from_u8(result); 
    }

    string decode(string str) {
        u32string u_str = to_u32(str);
        u32string u_abc = to_u32(alphabet);
        u32string u_key = to_u32(key);
        u32string result = U"";

        for (size_t i = 0; i < u_str.length(); i++) {
            size_t index_t = u_abc.find(u_str[i]);
            size_t index_k = u_abc.find(u_key[i % u_key.length()]);

            if (index_t != u32string::npos) {
                int shift = (index_k == u32string::npos) ? 0 : (int)index_k;
                int abc_len = u_abc.length();
                result += u_abc[(index_t - shift + abc_len) % abc_len];
            } else {
                result += u_str[i];
            }
        }
        return from_u32(result);
    }

private:
    string from_u8(const u32string& s) {
        wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
        return conv.to_bytes(s);
    }
};