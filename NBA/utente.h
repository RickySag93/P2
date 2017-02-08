#ifndef UTENTE_H
#define UTENTE_H
#include <QString>
class Utente
{
private:
   QString username,password;

public:
   Utente();
    Utente(QString, QString);
    QString getUsername() const;
    QString getPassword() const;
    void setUsername(QString);
    void setPassword(QString);
    bool operator==(Utente&) const;
    virtual bool isPremium() const;
    virtual ~Utente();
};

#endif // UTENTE_H
