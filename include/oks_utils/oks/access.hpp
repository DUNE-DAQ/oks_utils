#ifndef OKS_ACCESS_H
#define OKS_ACCESS_H

#include "oks/kernel.hpp"

namespace oks
{
  namespace access
  {
    /**
     * The function tests write access to database file.
     *
     * If the file is stored on OKS server repository, it checks access
     * permissions using Access Manager service. In this case optional user
     * name can be provided instead of current user taken by default.
     *
     * Otherwise it checks file system directory permissions for current user.
     */

    bool
    is_writable(const OksFile& file, const std::string& user = OksKernel::get_user_name());
  }
}

#endif
