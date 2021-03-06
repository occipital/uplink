// This file is part of Uplink, an easy-to-use cross-platform live RGBD streaming protocol.
// Copyright (c) 2016, Occipital, Inc.  All rights reserved.
// License: See LICENSE.

# pragma once

# include "./endpoints.h"

namespace uplink {

//------------------------------------------------------------------------------

struct ClientEndpoint : Endpoint
{
    virtual void onVersionInfo (const VersionInfo& clientVersionInfo);
    virtual void onSessionSetup(const uplink::SessionSetup &sessionSetup);
    virtual bool setupSession (const SessionSettings& nextSessionSettings) = 0;
    virtual void reset ();

    virtual void onSessionSetupSuccess () = 0;
    virtual void onSessionSetupFailure () = 0;

    virtual void onSessionSetupReply (const SessionSetupReply&)
    {
        // Nothing to do.

        // FIXME: Report. We're not supposed to receive that server-side-only message.
    }
};

//------------------------------------------------------------------------------

}

# include "./clients.hpp"
