// This file is part of Uplink, an easy-to-use cross-platform live RGBD streaming protocol.
// Copyright (c) 2016, Occipital, Inc.  All rights reserved.
// License: See LICENSE.

#pragma once

#include "platform.h"

namespace uplink {

inline
TCPConnection::TCPConnection ()
: disconnecting(false)
{
}

inline
TCPConnection::~TCPConnection ()
{
}

inline TCPConnection*
TCPConnection::connect (CString host, uint16 port)
{
    ScopedProfiledTask _(ProfilerTask_TCPConnection);

    return TCPConnection_connect(host, port);
}

inline TCPConnection*
TCPConnection::create  (int descriptor)
{
    return TCPConnection_create(descriptor);
}

} // uplink namespace
