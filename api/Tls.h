#pragma once

#include "Client.h"


namespace arduino {

// Tls CertificatesKeys are strings
using CertificateKey = const char[];

enum class CertificateFormat {
    Der,
    Pem,
}

class Tls: public ClientConnect {
public:
    virtual ~Tls() = default;

    enum IdentityVerification {
        MTls,       // both ends identity needs to be verified
        Tls,        // The server side end is verified against CA
        Insecure,   // no check against server side identity
    };

    virtual void setIdentityVerification(IdentityVerification mode) { _mode = mode; };
    virtual void setCA(CertificateKey ca, CertificateFormat f=CertificateFormat::Pem) = 0;
    virtual void setCertificate(CertificateKey public, CertificateKey private, CertificateFormat f=CertificateFormat::Pem) = 0;


    // Tls protocol enables Server Name Indication usage, for which a client provides
    // the hostname it is trying to connect to. This hostname may be required to be verified
    // against the server provided one
    virtual void sniVerification(bool) = 0;

    // manually provide an hostname that will be used together with sni
    // if connect is called with hostname as parameter this will be automatically called
    virtual void setHostname(const char hostname[]) = 0;
protected:
    IdentityVerification _mode;
};

class TlsClient: public Client, Tls {

};
}
