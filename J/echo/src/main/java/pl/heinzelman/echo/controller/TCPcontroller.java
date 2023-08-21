package pl.heinzelman.echo.controller;


import jakarta.servlet.ServletException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.io.IOException;

@Controller
public class TCPcontroller {

    @RequestMapping({"","/"})
    @ResponseBody
    String receive() throws IOException, ServletException {
        return "result";
    }
}
