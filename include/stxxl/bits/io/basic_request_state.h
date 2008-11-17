/***************************************************************************
 *  include/stxxl/bits/io/basic_request_state.h
 *
 *  UNIX file system file base
 *
 *  Part of the STXXL. See http://stxxl.sourceforge.net
 *
 *  Copyright (C) 2008 Andreas Beckmann <beckmann@cs.uni-frankfurt.de>
 *
 *  Distributed under the Boost Software License, Version 1.0.
 *  (See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 **************************************************************************/

#ifndef STXXL_BASIC_REQUEST_STATE_HEADER
#define STXXL_BASIC_REQUEST_STATE_HEADER

#include <stxxl/bits/io/iobase.h>
#include <stxxl/bits/io/basic_waiters_request.h>


__STXXL_BEGIN_NAMESPACE

//! \addtogroup fileimpl
//! \{

//! \brief Basic state implemenatition for most request implementations
class basic_request_state : public basic_waiters_request
{
protected:
    state<request_status> _state;

protected:
    basic_request_state(
        completion_handler on_cmpl,
        file * f,
        void * buf,
        stxxl::int64 off,
        size_t b,
        request_type t);

public:
    virtual ~basic_request_state();
    void wait();
    bool poll();
    const char * io_type() const;
};

//! \}

__STXXL_END_NAMESPACE

#endif // !STXXL_BASIC_REQUEST_STATE_HEADER
// vim: et:ts=4:sw=4
