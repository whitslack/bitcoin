// Copyright (c) 2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <kernel/checks.h>

#include <dbwrapper.h>
#include <random.h>
#include <util/result.h>
#include <util/translation.h>

#include <memory>

namespace kernel {

util::Result<void> SanityChecks(const Context&)
{
#if !EMBEDDED_LEVELDB
    if (!dbwrapper_SanityCheck()) {
        return util::Error{Untranslated("Database sanity check failure. Aborting.")};
    }
#endif

    if (!Random_SanityCheck()) {
        return util::Error{Untranslated("OS cryptographic RNG sanity check failure. Aborting.")};
    }

    return {};
}

}
