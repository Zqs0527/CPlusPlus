#include "crow_all.h"
using namespace std;
using namespace crow;

void sendFile(response &res, string fileName, string contentType){
     ifstream in("../public/" + fileName, ifstream::in);
        if (in)
        {
            ostringstream contents;
            contents << in.rdbuf();
            in.close();
            res.set_header("Content-Type", contentType);
            res.write(contents.str());
        } else{
            res.code = 404;
            res.write("Not found");
        }
        res.end();
}

void sendHtml(response &res, string fileName){
    sendFile(res, fileName + ".html", "text/html");
}

void sendImage(response &res, string fileName){
    sendFile(res, "images/" + fileName, "image/jpeg");
}

void sendScript(response &res, string fileName){
    sendFile(res, "scripts/" + fileName, "text/javascript");
}

void sendStyle(response &res, string fileName){
    sendFile(res, "styles/" + fileName, "text/css");
}
int main(int argc, char* argv[]){
    crow::SimpleApp app;

    CROW_ROUTE(app, "/styles/<string>")
    ([](const request &req, response &res, string fileName){
       sendStyle(res, fileName);
    });

     CROW_ROUTE(app, "/scripts/<string>")
    ([](const request &req, response &res, string fileName){
       sendScript(res, fileName);
    });

     CROW_ROUTE(app, "/images/<string>")
    ([](const request &req, response &res, string fileName){
       sendImage(res, fileName);
    });

    CROW_ROUTE(app, "/")
    ([](const request &req, response &res){
       sendHtml(res, "about");
    });
    char * port = getenv("PORT");
    uint16_t iPort = static_cast<uint16_t>(port != NULL?stoi(port):18080);
    cout << "PORT = " << iPort << "\n";
    app.port(iPort).multithreaded().run();
}