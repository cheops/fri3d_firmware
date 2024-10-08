#include <cstring>

#include "esp_log.h"

#include "fri3d_private/version.hpp"

namespace Fri3d::Apps::Ota
{

static const char *TAG = "Fri3d::Apps::Ota::CVersion";

CVersion::CVersion()
    : CVersion("0.0.0")
{
}

CVersion::CVersion(const CVersion &other)
    : CVersion()
{
    *this = other;
}

CVersion::CVersion(const char *version)
    : text(version)
    , semver({})
{
    if (text.empty())
    {
        text = "0.0.0";
    }

    auto result = semver_parse(this->text.c_str(), &this->semver);

    if (result != 0)
    {
        ESP_LOGW(TAG, "Could not parse version %s", version);
    }
}

CVersion::~CVersion()
{
    semver_free(&this->semver);
}

CVersion &CVersion::operator=(const CVersion &other)
{
    if (this != &other)
    {
        this->text = other.text;

        semver_free(&this->semver);

        // There is no copy function for semver, so we do it ourselves
        this->semver = other.semver;

        if (other.semver.metadata != nullptr)
        {
            this->semver.metadata = static_cast<char *>(calloc(strlen(other.semver.metadata) + 1, sizeof(char *)));
            strcpy(this->semver.metadata, other.semver.metadata);
        }
        if (other.semver.prerelease != nullptr)
        {
            this->semver.prerelease = static_cast<char *>(calloc(strlen(other.semver.prerelease) + 1, sizeof(char *)));
            strcpy(this->semver.prerelease, other.semver.prerelease);
        }
    }

    return *this;
}

CVersion &CVersion::operator=(CVersion &&other) noexcept
{
    this->text = std::move(other.text);

    this->semver = other.semver;
    other.semver = {};

    return *this;
}

CVersion CVersion::simplify() const
{
    CVersion result;

    result.semver = this->semver;
    result.semver.metadata = nullptr;
    result.semver.prerelease = nullptr;
    result.text = std::string(this->text, 0, this->text.find('-'));

    return result;
}

bool CVersion::empty() const
{
    return *this == CVersion();
}

bool CVersion::operator==(const CVersion &other) const
{
    return semver_eq(this->semver, other.semver);
}

bool operator<(const CVersion &l, const CVersion &r)
{
    return semver_compare(l.semver, r.semver) == -1;
}

bool operator>(const CVersion &l, const CVersion &r)
{
    return semver_compare(l.semver, r.semver) == 1;
}

} // namespace Fri3d::Apps::Ota
