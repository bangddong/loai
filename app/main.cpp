#include "httplib.h"
int main() {
    httplib::Server svr;
    svr.Get("/health", [](const httplib::Request&, httplib::Response& res){
        res.set_content("ok", "text/plain");
    });
    svr.Get("/", [](const httplib::Request&, httplib::Response& res){
        res.set_content("loai sim worker\n", "text/plain");
    });
    svr.listen("0.0.0.0", 8080);
}
