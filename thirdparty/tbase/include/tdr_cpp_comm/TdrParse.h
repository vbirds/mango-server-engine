/* This file is generated by tdr. */
/* No manual modification is permitted. */

/* tdr version: 2.7.16 */

#ifndef TSF4G_TDR_TDR_PARSE_H_
#define TSF4G_TDR_TDR_PARSE_H_

#include "TdrPal.h"
#include "TdrError.h"

namespace tsf4g_tdr
{


class TdrParse
{
    public:
        typedef TdrError::ErrorType (*MacroFunc)(int32_t& dest, const char* macro, const char* groupName);

    public:
        static TdrError::ErrorType
            parseUInt8(uint8_t& dest, const char* src, unsigned* parsed,
                    uint8_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUInt8(uint8_t* dest, unsigned count, const char* src, unsigned* parsed,
                    uint8_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt8(int8_t& dest, const char* src, unsigned* parsed,
                    int8_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt8(int8_t* dest, unsigned count, const char* src, unsigned* parsed,
                    int8_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseChar(char& dest, const char* src, unsigned* parsed,
                    char _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseChar(char* dest, unsigned count, const char* src, unsigned* parsed,
                    char _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUChar(unsigned char& dest, const char* src, unsigned* parsed,
                    unsigned char _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUChar(unsigned char* dest, unsigned count, const char* src, unsigned* parsed,
                    unsigned char _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUInt16(uint16_t& dest, const char* src, unsigned* parsed,
                        uint16_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUInt16(uint16_t* dest, unsigned count, const char* src, unsigned* parsed,
                        uint16_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt16(int16_t& dest, const char* src, unsigned* parsed,
                    int16_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt16(int16_t* dest, unsigned count, const char* src, unsigned* parsed,
                    int16_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUInt32(uint32_t& dest, const char* src, unsigned* parsed,
                        uint32_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUInt32(uint32_t* dest, unsigned count, const char* src, unsigned* parsed,
                        uint32_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt32(int32_t& dest, const char* src, unsigned* parsed,
                    int32_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt32(int32_t* dest, unsigned count, const char* src, unsigned* parsed,
                    int32_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUInt64(uint64_t& dest, const char* src, unsigned* parsed,
                        uint64_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseUInt64(uint64_t* dest, unsigned count, const char* src, unsigned* parsed,
                        uint64_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt64(int64_t& dest, const char* src, unsigned* parsed,
                    int64_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseInt64(int64_t* dest, unsigned count, const char* src, unsigned* parsed,
                    int64_t _default, MacroFunc macro, const char* groupName);

        static TdrError::ErrorType
            parseFloat(float& dest, const char* src, unsigned* parsed, float _default);

        static TdrError::ErrorType
            parseFloat(float* dest, unsigned count, const char* src, unsigned* parsed, float _default);

        static TdrError::ErrorType
            parseDouble(double& dest, const char* src, unsigned* parsed, double _default);

        static TdrError::ErrorType
            parseDouble(double* dest, unsigned count, const char* src, unsigned* parsed, double _default);

        static TdrError::ErrorType
            parseDate(tdr_date_t& dest, const char* src, unsigned* parsed, const char* _default);

        static TdrError::ErrorType
            parseDate(tdr_date_t* dest, unsigned count, const char* src, unsigned* parsed, const char* _default);

        static TdrError::ErrorType
            parseTime(tdr_time_t& dest, const char* src, unsigned* parsed, const char* _default);

        static TdrError::ErrorType
            parseTime(tdr_time_t* dest, unsigned count, const char* src, unsigned* parsed, const char* _default);

        static TdrError::ErrorType
            parseIP(tdr_ip_t& dest, const char* src, unsigned* parsed, const char* _default);

        static TdrError::ErrorType
            parseIP(tdr_ip_t* dest, unsigned count, const char* src, unsigned* parsed, const char* _default);
};

}
#endif
