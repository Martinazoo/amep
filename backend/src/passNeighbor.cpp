#include "passNeighbor.h"


// constructores i destructora
passNeighbor::passNeighbor()
{

}

passNeighbor::passNeighbor(string dni): _dni(dni)
{
    
}

passNeighbor::passNeighbor(string dni, unsigned int tokens): _dni(dni), _tokens(tokens)
{
    
}

passNeighbor::passNeighbor(string dni, string mail, string name, string username, 
        string password, unsigned int tokens): _dni(dni), _mail(mail), _name(name),
        _username(username), _password(password),_tokens(tokens)
{
    
}
//aquesta constructora s'utilitza només quan volem loggejar amb l'usuari i contrasenya introduits
passNeighbor::passNeighbor(string username, string password): _username(username), _password(password)
{

}

passNeighbor::~passNeighbor()
{

}

// insereix
void passNeighbor::insert()
{
    connection& c = connection::getInstance();
    
    c.executeUpdate("INSERT INTO amep11.neighbor (dni, mail, name, username, password, tokens) VALUES ('" + _dni + "', '" + _mail + "', '" + _name + "', '" + _username + "', '" + _password + "', '" + to_string(_tokens) + "')");
}

//loggeja (només utilitzar quan creem instància amb la constructora que només demana usuari i contrasenya)
void passNeighbor::log()
{
    bool logged = boolLog();
    if(logged)  
    {
        //si l'usuari i la contrasenya coincideixen amb els d'algun usuari de la BDD, entrem aquí
        cout <<"Credencials correctes, sessiò iniciada correctament."<<endl;
    }
    else
    {
        //si l'usuari no existeix al sistema o la contrasenya introduida no coincideix amb la que té l'usuari a la BDD, entrem aquí
        cout <<"Credencials incorrectes"<<endl;
    }
}

bool passNeighbor::boolLog()
{
    bool logged = false;
    try
    {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        //Parameters of the connection
        const std::string server_ip = "ubiwan.epsevg.upc.edu";
        const std::string user = "amep11";
        const std::string password = "zoxoX3feoYae-";

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(server_ip, user, password);

        // Initialize stmt before using it
        stmt = con->createStatement();

        res = stmt->executeQuery("SELECT * FROM amep11.neighbor WHERE username = '" + _username + "'");
        
        
        while(res->next())
        {
            //Comprovem que la contrasenya introduida és la mateixa que la registrada a la BDD
            if(res->getString("password") == _password)
            {
                logged = true;

                //Ara toca omplir la resta d'atributs del vei
                _dni = res->getString("dni");
                _mail = res->getString("mail");
                _name = res->getString("name");
                _tokens = res->getInt("tokens");
            }
        }   
        
        
        // Remember to clean up resources
        delete res;
        delete stmt;
        delete con;
    }
    catch(sql::SQLException &e)
    {
        cout << "SQL Exception: " << e.what() << endl;
    }
    return logged;
}

void passNeighbor::pay()
{
    //Aquesta funció s'encarrega de restar tokens al veí
    connection& c = connection::getInstance();
    string tokens = to_string(_tokens);
    c.executeUpdate("UPDATE amep11.neighbor SET tokens = tokens - '"+ tokens +"' WHERE dni = '" + _dni + "'");
}

void passNeighbor::charge()
{
    //Aquesta funció s'encarrega de sumar tokens al veí
    connection& c = connection::getInstance();
    string tokens = to_string(_tokens);
    c.executeUpdate("UPDATE amep11.neighbor SET tokens = tokens + '"+ tokens +"' WHERE dni = '" + _dni + "'");
}
// consultes per l'HU Register Neighbor

bool passNeighbor::existsDni(const string& dni) 
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    //paràmetres de la connexió
    const std::string server_ip = "ubiwan.epsevg.upc.edu";
    const std::string user = "amep11";
    const std::string password = "zoxoX3feoYae-";

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(server_ip, user, password);

    // consulta a la bdd
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT dni FROM amep11.neighbor");

    // s'obtenen els valors de tots els dni registrats
    std::vector<std::string> allDni;
    while (res->next()) {
        std::string dni = res->getString("dni");
        allDni.push_back(dni);
    }

     //netejar els recursos
        delete stmt;
        delete con;
        delete res; 

    // fem servir la funció std::find per mirar si el dni ja existeix a la bdd o no
    if (std::find(allDni.begin(), allDni.end(), dni) != allDni.end()) return true;
    else return false;
    
}

bool passNeighbor::existsMail(const string& mail) 
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    //paràmetres de la connexió
    const std::string server_ip = "ubiwan.epsevg.upc.edu";
    const std::string user = "amep11";
    const std::string password = "zoxoX3feoYae-";

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(server_ip, user, password);

    // consulta a la bdd
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT mail FROM amep11.neighbor");

    // s'obtenen els valors de tots els mails registrats
    std::vector<std::string> allMail;
    while (res->next()) {
        std::string mail = res->getString("mail");
        allMail.push_back(mail);
    }

     //netejar els recursos
        delete stmt;
        delete con;
        delete res; 

    // fem servir la funció std::find per mirar si el mail ja existeix a la bdd o no
    if (std::find(allMail.begin(), allMail.end(), mail) != allMail.end()) return true;
    else return false;


}

bool passNeighbor::existsUsername(const string& username)
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    //paràmetres de la connexió
    const std::string server_ip = "ubiwan.epsevg.upc.edu";
    const std::string user = "amep11";
    const std::string password = "zoxoX3feoYae-";

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(server_ip, user, password);

    // consulta a la bdd
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT username FROM amep11.neighbor");

    // s'obtenen els valors de tots els usernames registrats
    std::vector<std::string> allUsername;
    while (res->next()) {
        std::string username = res->getString("username");
        allUsername.push_back(username);
    }

     //netejar els recursos
        delete stmt;
        delete con;
        delete res; 

    // fem servir la funció std::find per mirar si el username ja existeix a la bdd o no
    if (std::find(allUsername.begin(), allUsername.end(), username) != allUsername.end()) return true;
    else return false;
    
}

// modifica
void passNeighbor::modify()
{
    connection& c = connection::getInstance();
    c.connect("UPDATE amep11.neighbor SET name = '"+_name+"', password = '"+_password+"' WHERE username = '"+_username+"';");
}

void passNeighbor::modify2()
{
     connection& c = connection::getInstance();
    c.executeUpdate("UPDATE amep11.neighbor SET mail = '" + _mail + "', name = '" + _name + "', username = '" + _username + "', password = '" + _password + "', tokens = '" + to_string(_tokens) + "' WHERE dni = '" + _dni + "'");
}

// esborra
void passNeighbor::erase()
{
    connection& c = connection::getInstance();
    cout << "nom user"<<_dni << endl;
    c.executeUpdate("DELETE FROM amep11.neighbor WHERE dni = '"+_dni+"'");
    cout << "eliminado" << endl;
}

// setters

void passNeighbor::setDni(string dni)
{
    _dni= dni;
}

void passNeighbor::setMail(string mail)
{
    _mail= mail; 
}

void passNeighbor::setName(string name)
{
    _name= name;
}

void passNeighbor::setUsername(string username)
{
    _username= username;
}

void passNeighbor::setPassword(string password)
{
    _password= password; 
}

void passNeighbor::setTokens(unsigned int tokens)
{
    _tokens= tokens; 
}     

// getters

string passNeighbor::getDni()
{
    return _dni; 
}

string passNeighbor::getMail()
{
    return _mail; 
}

string passNeighbor::getName()
{
    return _name; 
}

string passNeighbor::getUsername()
{
    return _username; 
}

string passNeighbor::getPassword()
{
    return _password; 
}

unsigned int passNeighbor::getTokens()
{
    return _tokens; 
}

